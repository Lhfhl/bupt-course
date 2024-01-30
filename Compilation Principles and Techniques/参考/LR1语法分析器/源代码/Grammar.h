#pragma once
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include"Production.h"
#include"DFA.h"
using namespace std;
//�ķ�����Ҫ�أ��ս�������ս�������ɹ�����ʼ��
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
	DFA item_cluster;//��Ŀ���淶���DFA
	map<pair<int,string>,string>action_table;//action��
	map<pair<int,string>,int>goto_table;//goto��
	map<string,set<string>> FIRST={};//FIRST����
	map<string,set<string>> FOLLOW={};//FOLLOW����
	vector<map<string,Production>> table={};//��ŷ�����	
	Production get_pdt(int num);//���ݲ���ʽ��Ż�ò���ʽ
	set<string> get_lookingahead(item target_item);//������Ŀ�������ǰ�����ż���
	set<item> closure(item i);//��ȡ�ķ��հ�

	int get_pdtnum(item target_item);//��ȡ����ʽ��ò���ʽ���
	void get_DFA();//�����ķ�����DFA ������ĥ�˵Ĺ���
	void remove_unreachable();//�������ɴ�״̬
	void get_emptypdt();//�жϸ������ս���Ƿ���¿�
	void get_grammar();//�����ķ�
	bool is_emptyable(Production p);//�ж�һ������ʽ�Ƿ���¿�
	bool is_num(string chs);//�ж�һ���ַ����Ƿ������֣�num��
	int is_repeated(State t);//�ж�״̬�Ƿ��Ѿ�����
	void get_FOLLOW();//����ķ���FOLLOW����
	void get_FIRST();//����ķ���FIRST����
	void pre_treat();//���ķ�����Ԥ����
	void analyze_string(string filename);//����һ��ָ���Ĵ�
	void show();//���չʾ
	void show_stack(vector<string> v);//չʾջ��Ԫ��
	void show_stack(vector<int> v);//չʾջ��Ԫ��
	void show_vector(vector<string> v,int k);//չʾ���봮
	void union_item();//�ϲ�״̬�е���Ŀ
	void get_table();//��дgoto��action��
	void show_cluster();//չʾ��Ŀ���淶��
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
