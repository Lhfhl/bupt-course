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
//文法构成要素：终结符，非终结符，生成规则，起始符

class Production//记录形如 A->B | C | d的产生式
{
public:
	vector<string> right;//产生式右部
};

class Grammar
{
public:
	Grammar(){};
	~Grammar(){};
	set<string> Vt={"#","$"};//终结符集合
	vector<string> Vn={};//非终结符集合
	map<string,int> Vn_num={};//获取非终结符的序号
	map<string,bool> is_empty={};//判断一个符号可否致空的数组
	string start;//起始符号
	map<string,vector<Production>> P={};//产生式集合
	
	void eliminate_recursion();//消除左递归
	void eliminate_public();//消除左前缀
	void remove_unreachable();//消除不可达状态
	void get_emptypdt();//判断各个非终结符是否可致空
	void get_grammar();//输入文法
	bool is_emptyable(Production p);//判断一个产生式是否可致空
	bool is_num(string chs);//判断一个字符串是否是数字（num）
	bool is_id(string chs);//判断一个字符串是否是标识符（identity）

	void get_FOLLOW();//获得文法的FOLLOW集合
	void get_FIRST();//获得文法的FIRST集合
	map<string,set<string>> FIRST={};//FIRST集合
	map<string,set<string>> FOLLOW={};//FOLLOW集合
	vector<map<string,Production>> table={};//存放分析表

	void get_analysis_table();//获取分析表
	void analyze_string(vector<string> token);//分析一个指定的串
	void show();//输出展示
	void show_stack(vector<string> v);//展示栈中元素
	void show_vector(vector<string> v,int k);//展示输入串
};
/*
		结构解释：
		如对于文法
		S->A|b
		A->c
		各个成员的值为：
		Vt={b,c};
		Vn={S,A};
		start=S;
		P[S]={A,b}
		P[A]={c}
	*/
//文法集合