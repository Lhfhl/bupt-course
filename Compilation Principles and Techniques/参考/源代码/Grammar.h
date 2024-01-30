#pragma once
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//�ķ�����Ҫ�أ��ս�������ս�������ɹ�����ʼ��

class Production//��¼���� A->B | C | d�Ĳ���ʽ
{
public:
	vector<string> right;//����ʽ�Ҳ�
};

class Grammar
{
public:
	Grammar(){};
	~Grammar(){};
	set<string> Vt={"#","$"};//�ս������
	vector<string> Vn={};//���ս������
	map<string,int> Vn_num={};//��ȡ���ս�������
	map<string,bool> is_empty={};//�ж�һ�����ſɷ��¿յ�����
	string start;//��ʼ����
	map<string,vector<Production>> P={};//����ʽ����
	
	void eliminate_recursion();//������ݹ�
	void eliminate_public();//������ǰ׺
	void remove_unreachable();//�������ɴ�״̬
	void get_emptypdt();//�жϸ������ս���Ƿ���¿�
	void get_grammar();//�����ķ�
	bool is_emptyable(Production p);//�ж�һ������ʽ�Ƿ���¿�
	bool is_num(string chs);//�ж�һ���ַ����Ƿ������֣�num��
	bool is_id(string chs);//�ж�һ���ַ����Ƿ��Ǳ�ʶ����identity��

	void get_FOLLOW();//����ķ���FOLLOW����
	void get_FIRST();//����ķ���FIRST����
	map<string,set<string>> FIRST={};//FIRST����
	map<string,set<string>> FOLLOW={};//FOLLOW����
	vector<map<string,Production>> table={};//��ŷ�����

	void get_analysis_table();//��ȡ������
	void analyze_string(vector<string> token);//����һ��ָ���Ĵ�
	void show();//���չʾ
	void show_stack(vector<string> v);//չʾջ��Ԫ��
	void show_vector(vector<string> v,int k);//չʾ���봮
};
/*
		�ṹ���ͣ�
		������ķ�
		S->A|b
		A->c
		������Ա��ֵΪ��
		Vt={b,c};
		Vn={S,A};
		start=S;
		P[S]={A,b}
		P[A]={c}
	*/
//�ķ�����