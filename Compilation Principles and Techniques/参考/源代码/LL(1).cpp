#include<iostream>
#include"Grammar.h"
using namespace std;
/*
	LL(1)�������죺
	1.����ֱ�ӡ������ݹ�
	2.��First��Follow��
	3.�������
*/
int main()
{
	Grammar G;//�����ķ�
	G.get_grammar();
	G.get_analysis_table();//��ȡ������
	G.show();
	//��ȡ���봮
	G.analyze_string({"a","c"});//�������봮
	return 0;
}