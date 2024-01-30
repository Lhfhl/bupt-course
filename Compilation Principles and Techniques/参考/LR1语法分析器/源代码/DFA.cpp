#include "DFA.h"
#include <queue>

/*bool State::is_equal(set<item> &a1,set<item> &a2)
{
    auto it1=a1.begin();
    auto it2=a2.begin();

    for(;it1!=a1.end()&&it2!=a2.end();it1++,it2++)
    {
        if(it1->left==it1->left&&it1->point==it2->point)
        {
            string p1="",p2="";

            for(int i=0;i<it1->pro.right.size();i++)
            {
                p1+=it1->pro.right[i];
            }
            for(int i=0;i<it2->pro.right.size();i++)
            {
                p2+=it2->pro.right[i];
            }
            if(p1!=p2)
            {
                return false;
            }
            if(it1->lookingahead_sign!=it2->lookingahead_sign)
            {
                return false;
            }
            continue;

        }
        else
        {
            return false;
        }
    }
    return true;
}*/


/*bool DFA::is_repeated(State t)
{   
    for(auto i=states.begin();i!=states.end();i++)
    {
        if(i->state_id!=t.state_id&&i->items==t.items)
        {
            return true;
        }
    }
    return false;
}*/

