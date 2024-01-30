#include "item.h"

item::item()
{
	point=0;
}

string item::get_next_sign()
{
	if(point<pro.right.size())
	{
		return pro.right[point];
	}
	return "";
}
