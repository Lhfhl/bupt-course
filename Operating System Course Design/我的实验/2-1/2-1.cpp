#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include<condition_variable>
std::mutex  g_cvMutex;    //��Ԫ�����ź���
std::condition_variable  g_cv;  //��������

//����������/buffer
std::deque<int> g_data_deque;
//������buffer�����Ŀ
const int  MAX_NUM = 30;
//������ָ��
int g_next_index = 0;

//�����ߣ��������̸߳���
const int PRODUCER_THREAD_NUM  = 3;
const int CONSUMER_THREAD_NUM = 3;


void  producer_thread(int thread_id)
{
	 while (true)
	 {
	     std::this_thread::sleep_for(std::chrono::milliseconds(500)); //�߳���ʱ��˯��
	     //�Ի��������м���
	     std::unique_lock <std::mutex> lk(g_cvMutex);
	     //������������δ��ʱ�������������
	     g_cv.wait(lk, [](){ return g_data_deque.size() <= MAX_NUM; }); //����δ��
	     g_next_index++;    //ָ������
	     g_data_deque.push_back(g_next_index);  //���ݼ������
	     std::cout << "producer_thread: " << thread_id << " producer data: " << g_next_index;
	     std::cout << " queue size: " << g_data_deque.size() << std::endl;
	     //���������߳� 
	     g_cv.notify_all();
	     //�Զ��ͷ���
	 }
}

void  consumer_thread(int thread_id)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(550));
        //�Ի��������м���
        std::unique_lock <std::mutex> lk(g_cvMutex);
        //��������Ƿ��ɣ����в�Ϊ�գ�������
        g_cv.wait(lk, []{return !g_data_deque.empty(); }); 
        //����������Ӷ�����ȡ����
        int data = g_data_deque.front();
        g_data_deque.pop_front();
        std::cout << "\tconsumer_thread: " << thread_id << " consumer data: ";
        std::cout << data << " deque size: " << g_data_deque.size() << std::endl;
        //���������߳�
        g_cv.notify_all();
        //�Զ��ͷ���
    }
}

int main()
{
    std::thread arrProducerThread[PRODUCER_THREAD_NUM];	//�������߳����� 
    std::thread arrConsumerThread[CONSUMER_THREAD_NUM];	//�������߳����� 

    for (int i = 0; i < PRODUCER_THREAD_NUM; i++)
    {
        arrProducerThread[i] = std::thread(producer_thread, i); //���ε����������߳� 0,1,2 
    }

    for (int i = 0; i < CONSUMER_THREAD_NUM; i++)
    {
        arrConsumerThread[i] = std::thread(consumer_thread, i);//���ε����������߳� 0,1,2
    }

    for (int i = 0; i < PRODUCER_THREAD_NUM; i++)
    {
        arrProducerThread[i].join(); //�ȴ��������߳�0,1,2���� 
    }

    for (int i = 0; i < CONSUMER_THREAD_NUM; i++)
    {
        arrConsumerThread[i].join(); //�ȴ��������߳�0,1,2����
    }
    
	return 0;
}
