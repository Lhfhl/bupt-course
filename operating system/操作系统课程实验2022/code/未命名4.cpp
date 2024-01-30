#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)
#define __USE_GNU
#include <sched.h>
#include <pthread.h>
#define ORANGE_MAX_VALUE 1000000
#define APPLE_MAX_VALUE 100000000
#define MSECOND 1000000
cpu_set_t mask;
int cpu_nums;

struct apple
{
       unsigned long long a;
       unsigned long long b;
};
struct orange
{
       int a[ORANGE_MAX_VALUE];
       int b[ORANGE_MAX_VALUE];
};

int set_cpu(int i)
{
	CPU_ZERO(&mask);
	if(2 <= cpu_nums)
	{
		CPU_SET(i,&mask);
		if(-1 == sched_setaffinity(gettid(),sizeof(&mask),&mask))
		{
			return -1;
		}
	}
	return 0;
}

void* add(void* x)
{
	if(-1 == set_cpu(1))
	{
		return NULL;
	}
	for(unsigned long long sum=0;sum<APPLE_MAX_VALUE;sum++)
	{
		((struct apple *)x)->a += sum;
		((struct apple *)x)->b += sum;
	}
	return NULL;
}
int main (int argc, const char * argv[]) {
	
	// insert code here...
	struct apple test;
	struct orange test1={{0},{0}};
	pthread_t ThreadA;
	
	cpu_nums = sysconf(_SC_NPROCESSORS_CONF);//配置的处理器个数 
	
	if(-1 == set_cpu(0))
	{
		return -1;
	}
	
	pthread_create(&ThreadA,NULL,add,&test);
	
	unsigned long long sum = 0; 
	for(unsigned long long index=0;index<ORANGE_MAX_VALUE;index++)
	{
		sum+=test1.a[index]+test1.b[index];
	}
	pthread_join(ThreadA,NULL);
	return 0;
}
