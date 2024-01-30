#pragma once
#include <map>
#include "item.h"

class State//一个状态相当于项目的合集
{
public:
	int state_id;//项目编号
	set<item> items;//项目集合
};

class DFA
{
public:
	vector<State> states;//状态集
	State start;//初始状态
	map<pair<int,string>,int>shift_func;//状态转移函数
	//bool is_repeated(State t);

};

