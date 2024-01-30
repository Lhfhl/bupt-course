#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Production//记录形如 A->B | C | d的产生式
{
public:
	int num;//产生式编号
	string left;//产生式左部
	vector<string> right;//产生式右部
};

