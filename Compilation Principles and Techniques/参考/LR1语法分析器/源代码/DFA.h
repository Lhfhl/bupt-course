#pragma once
#include <map>
#include "item.h"

class State//һ��״̬�൱����Ŀ�ĺϼ�
{
public:
	int state_id;//��Ŀ���
	set<item> items;//��Ŀ����
};

class DFA
{
public:
	vector<State> states;//״̬��
	State start;//��ʼ״̬
	map<pair<int,string>,int>shift_func;//״̬ת�ƺ���
	//bool is_repeated(State t);

};

