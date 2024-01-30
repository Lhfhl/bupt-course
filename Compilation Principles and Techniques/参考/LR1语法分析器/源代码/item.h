#pragma once
#include<iostream>
#include<iomanip>
#include<set>
#include"Production.h"
using namespace std;
class item
{
public:
	item();
	string left;//项目左边符号
	Production pro;//项目右边产生式
	set<string> lookingahead_sign;//向前看符号
	int point;//⚪点位置
	string get_next_sign();

};
