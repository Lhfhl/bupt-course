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
//文法构成要素：终结符，非终结符，生成规则，起始符
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
	DFA item_cluster;//项目集规范族的DFA
	map<pair<int,string>,string>action_table;//action表
	map<pair<int,string>,int>goto_table;//goto表
	map<string,set<string>> FIRST={};//FIRST集合
	map<string,set<string>> FOLLOW={};//FOLLOW集合
	vector<map<string,Production>> table={};//存放分析表	
	Production get_pdt(int num);//根据产生式编号获得产生式
	set<string> get_lookingahead(item target_item);//根据项目获得其向前看符号集合
	set<item> closure(item i);//获取文法闭包

	int get_pdtnum(item target_item);//获取产生式获得产生式编号
	void get_DFA();//根据文法构造DFA 究极折磨人的过程
	void remove_unreachable();//消除不可达状态
	void get_emptypdt();//判断各个非终结符是否可致空
	void get_grammar();//输入文法
	bool is_emptyable(Production p);//判断一个产生式是否可致空
	bool is_num(string chs);//判断一个字符串是否是数字（num）
	int is_repeated(State t);//判断状态是否已经存在
	void get_FOLLOW();//获得文法的FOLLOW集合
	void get_FIRST();//获得文法的FIRST集合
	void pre_treat();//对文法进行预处理
	void analyze_string(string filename);//分析一个指定的串
	void show();//输出展示
	void show_stack(vector<string> v);//展示栈中元素
	void show_stack(vector<int> v);//展示栈中元素
	void show_vector(vector<string> v,int k);//展示输入串
	void union_item();//合并状态中的项目
	void get_table();//填写goto和action表
	void show_cluster();//展示项目集规范族
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
