#include<iostream>
#include"Grammar.h"
using namespace std;
/*
	LR(1)�������죺
	1.�����ķ�
	2.������Ŀ���淶��
	3.����ʶ�����л�ǰ׺��DFA
	4.��д������
*/
int main()
{
	Grammar G;//�����ķ�
	G.get_grammar();
	G.pre_treat();//Ԥ�����ķ�
	G.show();//չʾ�ķ�
	G.analyze_string("chs");

	return 0;
}