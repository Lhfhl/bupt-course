#include<iostream>
#include"Grammar.h"
using namespace std;
/*
	LR(1)分析表构造：
	1.读入文法
	2.构造项目集规范族
	3.构造识别所有活前缀的DFA
	4.填写分析表
*/
int main()
{
	Grammar G;//构造文法
	G.get_grammar();
	G.pre_treat();//预处理文法
	G.show();//展示文法
	G.analyze_string("chs");

	return 0;
}