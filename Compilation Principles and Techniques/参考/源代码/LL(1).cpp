#include<iostream>
#include"Grammar.h"
using namespace std;
/*
	LL(1)分析表构造：
	1.消除直接、间接左递归
	2.找First、Follow集
	3.填分析表
*/
int main()
{
	Grammar G;//构造文法
	G.get_grammar();
	G.get_analysis_table();//获取分析表
	G.show();
	//获取输入串
	G.analyze_string({"a","c"});//分析输入串
	return 0;
}