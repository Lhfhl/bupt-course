#include "Grammar.h"
#include <iomanip>
#include <queue>
int step=1;

bool operator ==(const item &a1,const item &a2)
{
	auto it1=&a1;
	auto it2=&a2;
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
	}
	else
	{
		return false;
	}
	return true;
}

bool operator <(const item &a1,const item &a2)
{
	if(a1.left!=a2.left)
	{
		return a1.left<a2.left;
	}
	else if(a1.point!=a2.point)
	{
		return a1.point<a2.point;
	}
	else if(a1.lookingahead_sign!=a2.lookingahead_sign)
	{
		if(a1.lookingahead_sign.size()!=a2.lookingahead_sign.size())
		{
			return a1.lookingahead_sign.size()<a2.lookingahead_sign.size();
		}

		auto i=a1.lookingahead_sign.begin(),j=a2.lookingahead_sign.begin();
		for(;i!=a1.lookingahead_sign.end(),j!=a2.lookingahead_sign.end();i++,j++)
		{
			if(*i!=*j)
			{
				return *i<*j;
			}
		}
		
	}
	else
	{
		if(a1.pro.num!=a2.pro.num)
		{
			return a1.pro.num<a2.pro.num;
		}
	}
	return false;
	
}

bool operator ==(const set<item> &a1,const set<item> &a2)
{
	auto it1=a1.begin();
	auto it2=a2.begin();

	for(; it1!=a1.end(),it2!=a2.end(); it1++,it2++)
	{
		item a=*it1;
		item b=*it2;
		if(!(a==b))
		{
			return false;
		}
	}
	if(it1!=a1.end()||it2!=a2.end())
	{
		return false;
	}
	return true;
}

bool operator <(const State &s1,const State &s2)
{
	if(!(s1.items==s2.items))
	{
		if(s1.items.size()!=s2.items.size())
			return s1.items.size()<s2.items.size();

		auto i=s1.items.begin(),j=s2.items.begin();
		for(;i!=s1.items.end(),j!=s1.items.end();i++,j++)
		{
			if(!(*i==*j))
			{
				return *i<*j;
			}
		}
	}
}

void Grammar::show_cluster()
{
	cout<<endl<<"项目集规范族："<<endl;
	for(int i=0;i<item_cluster.states.size();i++)
	{
		cout<<"状态I("<<item_cluster.states[i].state_id<<")："<<endl;
		for(auto j:item_cluster.states[i].items)
		{
			cout<<"["<<j.pro.left<<"->";
			for(int k=0;k<j.pro.right.size();k++)
			{
				if(k==j.point)
				{
					cout<<"·";
				}
				cout<<j.pro.right[k];
			}
			if(j.point==j.pro.right.size())
				cout<<"·";

			cout<<"，";
			if(!j.lookingahead_sign.empty())
			{
				cout<<*(j.lookingahead_sign.begin());
			}
			if(j.lookingahead_sign.size()>1)
			{
				auto k=j.lookingahead_sign.begin();
				k++;
				for(;k!=j.lookingahead_sign.end();k++)
				{
					cout<<"|"<<*k;
				}
			}
			cout<<"]"<<endl;

		}
		cout<<endl;
	}

}

int Grammar::get_pdtnum(item target_item)
{
	return target_item.pro.num;
}

Production Grammar::get_pdt(int num)
{
	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			if(P[Vn[i]][j].num==num)
			{
				return P[Vn[i]][j];
			}
		}
	}
}

set<string> Grammar::get_lookingahead(item target_item)
{
	set<string> new_las;
	string cur_string=target_item.pro.right[target_item.point+1];

	if(Vt.find(cur_string)!=Vt.end())
	{
		new_las.insert(cur_string);
	}
	else
	{
		new_las=FIRST[cur_string];
	}
	
	
	int loc=target_item.point+1;
	while(new_las.find("#")!=new_las.end())
	{
		new_las.erase("#");//擦去空符号，同时进行下一步动作
		if(loc!=target_item.pro.right.size())
		{
			cur_string=target_item.pro.right[loc];

			if(Vt.find(cur_string)!=Vt.end())
			{
				new_las.insert(cur_string);
			}
			else
			{
				set_union(
					new_las.begin(),
					new_las.end(),
					target_item.lookingahead_sign.begin(),
					target_item.lookingahead_sign.end(),
					inserter(new_las,new_las.begin())
				);
			}
		}
		else
		{
			set_union(
				new_las.begin(),
				new_las.end(),
				FIRST[cur_string].begin(),
				FIRST[cur_string].end(),
				inserter(new_las,new_las.begin())
			);
		}
	}
	return new_las;
}

set<item> Grammar::closure(item i)
//求项目i的闭包
{
	//计算closure实为利用了bfs的思想
	set<item> cls;
	queue<item> q;

	cls.insert(i);//将大队长加入闭包
	q.push(i);//将大队长加入状态机

	while(!q.empty())
	{
		item cur=q.front();
		q.pop();

		if(cur.pro.right.size()==1&&cur.pro.right[0]=="#")
		{
			cur.pro.right[0]="";
		}
		if(!(cur.point==cur.pro.right.size()))
		//原点在最后一个位置，没有后续动作,否则需要进一步分析
		{
			//S->·ABC
			string new_sign=cur.pro.right[cur.point];
			set<string> new_las;//向前看符号集

			if(cur.point==cur.pro.right.size()-1)
			{
				new_las=cur.lookingahead_sign;//继承原有的向前看符号
			}
			else
			{
				new_las=get_lookingahead(cur);//根据项目获得其向前看符号集合
			}

			for(int pi=0;pi<P[new_sign].size();pi++)
			{
				item temp;
				temp.left=new_sign;
				temp.point=0;
				temp.pro=P[new_sign][pi];
				temp.lookingahead_sign=new_las;
				if(cls.insert(temp).second)
				{
					q.push(temp);
				}
				
			}
			
		}
	}

	return cls;
}

void Grammar::get_DFA()//构造自动(bi)机
{
	//Designed by 庞可涵
	int state_num=0;
	State s0;
	item start_item;
	start_item.left=start;
	start_item.lookingahead_sign={"$"};
	start_item.point=0;
	start_item.pro=P[start][0];
	s0.items=closure(start_item);
	s0.state_id=state_num++;

	item_cluster.start=s0;
	item_cluster.states.push_back(s0);

	for(int i=0;i<item_cluster.states.size();i++)
	{
		//构造该状态可以引出的所有边
		//虽然思想与BFS吻合，但是因为要保存所有的状态，所以用vector当队列也无妨
		map<string,State> move;//转移映射，用于记录某个转移符号所要到达的状态

		for(auto j=item_cluster.states[i].items.begin();j!=item_cluster.states[i].items.end();j++)
		{
			if(j->point<j->pro.right.size())//如果是移进项目或待约项目
			{
				string cur_sign=j->pro.right[j->point];//当前引起转移的符号
				item new_item=*j;//新的大队长
				new_item.point++;//圆点往前移一位

				set<item> next_state_item=closure(new_item);
				//大队长和他的小组长们

				if(move.find(cur_sign)!=move.end())
				//已经有这个转移对应的状态了,将新得到的闭包合并
				{
					set_union(
						move[cur_sign].items.begin(),
						move[cur_sign].items.end(),
						next_state_item.begin(),
						next_state_item.end(),
						inserter(move[cur_sign].items,move[cur_sign].items.begin())
					);
				}
				else
				//还没有创建这个转移对应的状态，构造新状态
				{
					State temp;
					temp.items=next_state_item;
					move.insert({cur_sign,temp});
				}

			}
		}

		for(auto j=move.begin();j!=move.end();j++)
		{
			int id=is_repeated(j->second);
			if(id==-1)//重复的状态不再加入
			{
				j->second.state_id=state_num++;
				item_cluster.states.push_back(j->second);//将新的得到的状态加入"队列"(雾
				pair<int,string> l={item_cluster.states[i].state_id,j->first};
				item_cluster.shift_func.insert({l,j->second.state_id});
			}
			else
			{
				pair<int,string> l={item_cluster.states[i].state_id,j->first};
				item_cluster.shift_func.insert({l,id});
			}
		}

	}


}

void Grammar::remove_unreachable()//消除不可达符号实际上为DFS
{
	bool *is_instack=new bool[Vn.size()+1];
	bool *is_retain=new bool[Vn.size()+1];
	for(int i=0;i<Vn.size();i++)
	{
		is_instack[i]=false;
		is_retain[i]=false;
	}
	
	stack<string> s;
	s.push(start);
	is_instack[Vn_num[start]]=true;
	is_retain[Vn_num[start]]=true;
	while(!s.empty())
	{
		string cur_vn=s.top();
		s.pop();
		is_instack[Vn_num[cur_vn]]=false;
		for(int i=0;i<P[cur_vn].size();i++)
		{
			for(int j=0;j<P[cur_vn][i].right.size();j++)
			{
				string temp_sign=P[cur_vn][i].right[j];
				if(Vt.find(temp_sign)==Vt.end())
				{
					if(!is_instack[Vn_num[temp_sign]]&&!is_retain[Vn_num[temp_sign]])
					{
						s.push(temp_sign);
						is_instack[Vn_num[temp_sign]]=true;
						is_retain[Vn_num[temp_sign]]=true;
					}
				}
			}
		}
	}

	map<string,vector<Production>> new_P;
	vector<string> new_Vn;

	Vn_num.clear();
	int k=0;
	for(int i=0;i<Vn.size();i++)
	{
		if(is_retain[i])
		{
			new_Vn.push_back(Vn[i]);
			Vn_num.insert(make_pair(Vn[i],k++));
			new_P.insert(make_pair(Vn[i],P[Vn[i]]));
		}
	}
	Vn=new_Vn;
	P=new_P;
}

void Grammar::get_emptypdt()
{
	for(int i=0;i<Vn.size();i++)
	{
		is_empty.insert({Vn[i],false});
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			if(P[Vn[i]][j].right.size()==1&&P[Vn[i]][j].right[0]=="#")
			{
				is_empty[Vn[i]]=true;
				break;
			}
		}
	}

	bool is_change=false;

	while(!is_change)
	{
		is_change=true;
		for(int i=0;i<Vn.size();i++)
		{
			if(is_empty[Vn[i]]==false)
			{
				for(int j=0;j<P[Vn[i]].size()&&is_empty[Vn[i]]==false;j++)
				{
					is_empty[Vn[i]]=true;
					for(int k=0;k<P[Vn[i]][j].right.size();k++)
					{
						if(!is_empty[P[Vn[i]][j].right[k]])
						{
							is_empty[Vn[i]]=false;
							break;
						}
					}
					is_change=!is_empty[Vn[i]];
				}
			}
		}
	}
}

void Grammar::get_grammar()
{
	ifstream infile;
	infile.open("input.txt");
	int numof_vt,numof_vn,numof_pdc;//终结符，非终结符，产生式数量
	infile>>numof_vt>>numof_vn>>numof_pdc;//输入各个符号的数量
	for(int i=0;i<numof_vt;i++)
	{
		string vt_temp;//终极符临时对象
		infile>>vt_temp;
		Vt.insert(vt_temp);
	}
	for(int i=0;i<numof_vn;i++)
	{
		string vn_temp;
		vector<Production> pdt_temp;
		infile>>vn_temp;
		Vn.push_back(vn_temp);
		Vn_num.insert(make_pair(vn_temp,i));
		P.insert(make_pair(vn_temp,pdt_temp));
	}
	char cur_line[512]="";
	infile.getline(cur_line,512);
	for(int i=0;i<numof_pdc;i++)
	{
		string vn_temp="";//产生式左边的非终结符
		string pdc_temp="";//产生式右边读取的字符
		Production pdc;//构造表达式用的临时变量
		int j=0;
		memset(cur_line,'\0',512);
		infile.getline(cur_line,512);
		while(cur_line[j]!='-')
			vn_temp+=cur_line[j++];
		(j++);
		j++;
		while(cur_line[j]!='\n'&&cur_line[j]!='\0')
		{
			while(cur_line[j]!=' '&&cur_line[j]!='\n'&&cur_line[j]!='\0')
				pdc_temp+=cur_line[j++];
			pdc.right.push_back(pdc_temp);
			pdc_temp="";
			j++;
		}
		P[vn_temp].push_back(pdc);
		
	}
	infile>>start;//最后一行为开始符号
	infile.close();
}

bool Grammar::is_emptyable(Production p)
{
	for(int i=0;i<p.right.size();i++)
	{
		string cur_string=p.right[i];
		if(Vt.find(cur_string)!=Vt.end())
		{
			if(cur_string!="#")
				return false;
		}
		else
		{
			if(!is_empty[cur_string])
				return false;
		}
	}

	return true;
}

bool Grammar::is_num(string chs)
{
	for(int i=0;i<chs.size();i++)
	{
		if(chs[i]>'9'||chs[i]<'0')
			return false;
	}
	return true;
}

int Grammar::is_repeated(State t)
{
	for(auto i=item_cluster.states.begin();i!=item_cluster.states.end();i++)
	{
		if(i->items==t.items)
		{
			return i->state_id;
		}
	}
	return -1;
}

void Grammar::get_FOLLOW()
{
	stack<int> s;//先将各个FRIST集合合并入FOLLOW集合中
	for(int i=0;i<Vn.size();i++)
	{
		set<string> temp={};
		FOLLOW.insert({Vn[i],temp});
	}

	FOLLOW[start].insert("$");

	int **is_join=new int *[Vn.size()+1];
	for(int i=0;i<Vn.size();i++)
	{
		is_join[i]=new int[Vn.size()+1];
	}
	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<Vn.size();j++)
		{
			is_join[i][j]=0;
		}
	}

	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			for(int k=0;k<P[Vn[i]][j].right.size()-1;k++)
			{
				if(Vt.find(P[Vn[i]][j].right[k])!=Vt.end())
				{
					//是终结符，无事发生
				}
				else
				{
					if(Vt.find(P[Vn[i]][j].right[k+1])!=Vt.end())//下一个字符是终结符
					{
						FOLLOW[P[Vn[i]][j].right[k]].insert(P[Vn[i]][j].right[k+1]);
					}
					else//是非终结符，则需要加入其FIRST集的元素
					{

						if(k+1==P[Vn[i]][j].right.size()-1)
						{
							int num=Vn_num[P[Vn[i]][j].right[k+1]];
							is_join[i][num]=1;
						}
						
						int m=k+1;
						while(m<P[Vn[i]][j].right.size())
						{
							if(Vt.find(P[Vn[i]][j].right[k])!=Vt.end())
							{
								break;
							}
							if(!(m==k+1||is_empty[Vn[m]]==true))
							{
								break;
							}
							set<string> temp;
							set_union(
								FOLLOW[P[Vn[i]][j].right[k]].begin(),
								FOLLOW[P[Vn[i]][j].right[k]].end(),
								FIRST[P[Vn[i]][j].right[m]].begin(),
								FIRST[P[Vn[i]][j].right[m]].end(),
								inserter(temp,temp.begin())
								);
							FOLLOW[P[Vn[i]][j].right[k]]=temp;
							auto loc=FOLLOW[P[Vn[i]][j].right[k]].find("#");
							if(loc!=FOLLOW[P[Vn[i]][j].right[k]].end())
							{
								FOLLOW[P[Vn[i]][j].right[k]].erase(loc);
							}
							m++;
						}
						
						if(m==P[Vn[i]][j].right.size())//如果是最后一个元素，说明需要进行额外的添加工作
						{					
							int num=Vn_num[P[Vn[i]][j].right[k]];
							is_join[i][num]=1;//应该把i的FOLLOW集加入到num的FOLLOW集中
						}


					}
				}
			}
			int loc=P[Vn[i]][j].right.size()-1;
			string end_string=P[Vn[i]][j].right[loc];
			if(Vt.find(end_string)==Vt.end())
			{
				is_join[i][Vn_num[end_string]]=1;
			}
		}
	}

	bool end=true;
	
	while(end)
	{
		end=false;
		for(int i=0;i<Vn.size();i++)
		{
			for(int j=0;j<Vn.size();j++)
			{
				if(is_join[i][j])
				{
					set<string> temp;
					int num1=FOLLOW[Vn[j]].size();
					std::set_union(
						FOLLOW[Vn[i]].begin(),
						FOLLOW[Vn[i]].end(),
						FOLLOW[Vn[j]].begin(),
						FOLLOW[Vn[j]].end(),
						inserter(temp,temp.begin())

					);
					FOLLOW[Vn[j]]=temp;
					auto loc=FOLLOW[Vn[j]].find("#");
					if(loc!=FOLLOW[Vn[j]].end())
					{
						FOLLOW[Vn[j]].erase(loc);
					}
					int num2=FOLLOW[Vn[j]].size();
					end=!(num1==num2);
				}
			}
		}
	}
	
}

void Grammar::get_FIRST()
{
	stack<int> s;//利用DFS思想求所有非终结符的FIRST集合
	bool *is_finish=new bool[Vn.size()+1];
	bool *is_instack=new bool[Vn.size()+1];
	for(int i=0;i<Vn.size();i++)
	{
		is_finish[i]=false;
		is_instack[i]=false;
		set<string> temp={};
		FIRST.insert({Vn[i],temp});
	}
	int **is_join=new int *[Vn.size()+1];
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        	for(int i=0;i<Vn.size();i++)
	{
		is_join[i]=new int[Vn.size()+1];
	}
	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<Vn.size();j++)
		{
			is_join[i][j]=0;
		}
	}
	for(int i=0;i<Vn.size();i++)
	{
		if(is_finish[i])
			continue;
		s.push(i);
		is_instack[i]=true;
		while(!s.empty())
		{
			int cur_sign=s.top();//弹出一个非终结符
			set<string> temp;
			bool finish=true;
			bool pop=true;
			for(int j=0;j<P[Vn[cur_sign]].size();j++)//对于该终结符的所有产生式
			{
				for(int k=0;k<P[Vn[cur_sign]][j].right.size();k++)
				{
					string cur_string=P[Vn[cur_sign]][j].right[k];

					if(cur_string==Vn[cur_sign])
						break;


					if(k!=0&&!is_empty[Vn[k-1]])
					{
						break;
					}

					if(Vt.find(cur_string)==Vt.end())//非终结符处理：
					{
						is_join[cur_sign][Vn_num[cur_string]]=1;
						if(is_finish[Vn_num[cur_string]])
							//如果该非终结符FIRST集已知
						{
							set<string> temp;
							set_union(
								FIRST[Vn[cur_sign]].begin(),
								FIRST[Vn[cur_sign]].end(),
								FIRST[cur_string].begin(),
								FIRST[cur_string].end(),
								inserter(temp,temp.begin())
							);//取并集
							FIRST[Vn[cur_sign]]=temp;
						}
						else if(is_instack[Vn_num[cur_string]])//虽然未知，但是在栈里
						{
							set<string> temp;
							set_union(
								FIRST[Vn[cur_sign]].begin(),
								FIRST[Vn[cur_sign]].end(),
								FIRST[cur_string].begin(),
								FIRST[cur_string].end(),
								inserter(temp,temp.begin())
							);//取并集
							FIRST[Vn[cur_sign]]=temp;
						}
						else//又是未知的，又不在栈里
						{
							s.push(Vn_num[cur_string]);//将该非终结符加入栈
							finish=false;
							pop=false;
						}
					}
					else
					{
						FIRST[Vn[cur_sign]].insert(cur_string);//将终结符加入集合
					}

					if(k==P[Vn[cur_sign]][j].right.size()-1&&is_empty[Vn[k]])
					{
						FIRST[Vn[cur_sign]].insert("#");
					}
					else
					{
						if(!is_empty[Vn[cur_sign]])
						{
							auto loc=FIRST[Vn[cur_sign]].find("#");
							if(loc!=FIRST[Vn[cur_sign]].end())
							{
								FIRST[Vn[cur_sign]].erase(loc);
							}
						}
					}
				}
				
			}
			if(finish||pop)
				s.pop();
			is_finish[cur_sign]=finish;
		}
	}

	bool end=true;

	while(end)
	{
		end=false;
		for(int i=0;i<Vn.size();i++)
		{
			for(int j=0;j<Vn.size();j++)
			{
				if(is_join[j][i])
				{
					set<string> temp;
					int num1=FIRST[Vn[j]].size();
					std::set_union(
						FIRST[Vn[i]].begin(),
						FIRST[Vn[i]].end(),
						FIRST[Vn[j]].begin(),
						FIRST[Vn[j]].end(),
						inserter(temp,temp.begin())

					);
					FIRST[Vn[j]]=temp;
					auto loc=FIRST[Vn[j]].find("#");
					if(loc!=FIRST[Vn[j]].end())
					{
						FIRST[Vn[j]].erase(loc);
					}
					int num2=FIRST[Vn[j]].size();
					end=!(num1==num2);
				}
			}
		}
	}

}

void Grammar::pre_treat()//填写分析表
{
	string old_start=start;
	start+="'";
	vector<string> new_Vn;
	new_Vn.push_back(start);
	new_Vn.insert(new_Vn.end(),Vn.begin(),Vn.end());
	Vn=new_Vn;
	Production new_pro;
	new_pro.right.push_back(old_start);
	P.insert({start,{new_pro}});
	
	map<string,int> new_Vn_num;
	for(int i=0;i<Vn.size();i++)
	{
		new_Vn_num.insert({Vn[i],i});
	}
	Vn_num=new_Vn_num;

	remove_unreachable();//消除不可达状态
	get_emptypdt();
	get_FIRST();//获取FIRST集合
	
	int k=0;
	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			P[Vn[i]][j].left=Vn[i];
			P[Vn[i]][j].num=k++;
		}
	}
	get_DFA();
	union_item();
	get_table();
}

void Grammar::analyze_string(string filename)
{
	ifstream infile;
	infile.open(filename+".txt");
	vector<string>token;
	string tobe_analysis;
	while(infile>>tobe_analysis)
	{
		token.push_back(tobe_analysis);
	}
	token.push_back("$");

	cout<<"待分析字符串："<<endl;
	show_vector(token,0);
	
	for(int i=0;i<token.size();i++)
	{
		if(is_num(token[i]))
		{
			token[i]="num";
		}
	}
	cout<<"分析开始："<<endl;
	
	vector<string> symbols;//符号栈
	vector<int> sts;//状态栈
	sts.push_back(0);
	symbols.push_back("-");
	int k=0;//分析进行位置

	while(k!=token.size())
	{
		cout<<"----------------------------Step："<<step++<<"----------------------------"<<endl;
		show_stack(sts);
		show_stack(symbols);
		show_vector(token,k);
		int cur_state=sts.back();
		pair<int,string> temp={cur_state,token[k]};

		if(action_table.find(temp)!=action_table.end())
		{
			string action=action_table[temp];
			if(action[0]=='s')//应该移进
			{
				string new_state_string="";
				new_state_string.insert(new_state_string.begin(),action.begin()+1,action.end());
				int new_state=atoi(new_state_string.c_str());
				sts.push_back(new_state);
				symbols.push_back(token[k++]);
				cout<<"分析动作：Shift "<<new_state<<endl;
			}
			else if(action[0]=='r')//应该归约
			{
				string pdt_string="";
				pdt_string.insert(pdt_string.begin(),action.begin()+1,action.end());
				int pdt_num=atoi(pdt_string.c_str());//归约使用的产生式编号

				Production pdt=get_pdt(pdt_num);
				int num=pdt.right.size();

				while(num--)
				{
					symbols.pop_back();
					sts.pop_back();
				}

				symbols.push_back(pdt.left);
				pair<int,string> temp={sts.back(),pdt.left};
				if(goto_table.find(temp)!=goto_table.end())
				{
					sts.push_back(goto_table[temp]);
				}
				else
				{
					goto label;
				}
				cout<<"分析动作：Reduce by ";
				cout<<pdt.left<<"->";
				for(int i=0;i<pdt.right.size();i++)
				{
					cout<<pdt.right[i];
				}
				cout<<endl;
			}
			else
			{
				break;
			}
		}
		else
		{
			label: cout<<"语法错误！"<<endl;
			exit(1);
		}

	}

	cout<<"分析结束！"<<endl;
}

void Grammar::show()
{
	for(int i=0;i<Vn.size();i++)
	{
		string temp_vn=Vn[i];
		for(int j=0;j<P[temp_vn].size();j++)
		{
			cout<<P[temp_vn][j].num<<"："<<temp_vn<<" -> ";
			for(int k=0;k<P[temp_vn][j].right.size();k++)
			{
				cout<<P[temp_vn][j].right[k]<<" ";
			}
			cout<<endl;
		}
	}
	cout<<endl<<"项目集规范族："<<endl;
	for(int i=0;i<item_cluster.states.size();i++)
	{
		cout<<"状态I("<<item_cluster.states[i].state_id<<")："<<endl;
		for(auto j:item_cluster.states[i].items)
		{
			cout<<"["<<j.pro.left<<"->";
			for(int k=0;k<j.pro.right.size();k++)
			{
				if(k==j.point)
				{
					cout<<"·";
				}
				cout<<j.pro.right[k];
			}
			if(j.point==j.pro.right.size())
				cout<<"·";

			cout<<"，";
			if(!j.lookingahead_sign.empty())
			{
				cout<<*(j.lookingahead_sign.begin());
			}
			if(j.lookingahead_sign.size()>1)
			{
				auto k=j.lookingahead_sign.begin();
				k++;
				for(;k!=j.lookingahead_sign.end();k++)
				{
					cout<<"|"<<*k;
				}
			}
			cout<<"]"<<endl;
			
		}
		cout<<endl;
	}

	cout<<"action表："<<endl;
	cout<<'\t';
	for(auto i=Vt.begin();i!=Vt.end();i++)
	{
		if(*i!="#")
		{
			cout<<*i<<'\t';
		}
	}
	cout<<endl;
	for(int i=0;i<item_cluster.states.size();i++)
	{
		cout<<item_cluster.states[i].state_id<<'\t';
		for(auto j=Vt.begin();j!=Vt.end();j++)
		{
			if(*j!="#")
			{
				if(action_table.find({item_cluster.states[i].state_id,*j})!=action_table.end())
				{
					cout<<action_table[{item_cluster.states[i].state_id,*j}]<<'\t';
				}
				else
				{
					cout<<"  "<<'\t';
				}
			}
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"goto表："<<endl;
	cout<<'\t';
	for(auto i=Vn.begin();i!=Vn.end();i++)
	{
		if(*i!=start)
			cout<<*i<<'\t';
	}
	cout<<endl;
	for(int i=0;i<item_cluster.states.size();i++)
	{
		cout<<item_cluster.states[i].state_id<<'\t';
		for(auto j=Vn.begin();j!=Vn.end();j++)
		{
			if(*j==start)
				continue;
			if(goto_table.find({item_cluster.states[i].state_id,*j})!=goto_table.end())
			{
				cout<<goto_table[{item_cluster.states[i].state_id,*j}]<<'\t';
			}
			else
			{
				cout<<"  "<<'\t';
			}
		}
		cout<<endl;
	}
	//这部分LL(1)的是不是可以不要了？舍不得删掉 留下吧
	/*for(int i=0;i<FIRST.size();i++)
	{
		cout<<"FRIST("<<Vn[i]<<")={ ";
		for(auto j=FIRST[Vn[i]].begin();j!=FIRST[Vn[i]].end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<"}"<<endl;
	}

	for(int i=0;i<FOLLOW.size();i++)
	{
		cout<<"FOLLOW("<<Vn[i]<<")={ ";
		for(auto j=FOLLOW[Vn[i]].begin();j!=FOLLOW[Vn[i]].end();j++)
		{
			cout<<*j<<" ";
		}
		cout<<"}"<<endl;
	}
	cout<<"\t";;
	cout<<"\t";;
	for(auto j=Vt.begin();j!=Vt.end();j++)
	{
		if(*j!="#"&&*j!="$")
			cout<<*j<<'\t';
	}
	cout<<endl;
	for(int i=0;i<Vn.size();i++)
	{
		cout<<Vn[i]<<"\t:";
		for(auto j=Vt.begin();j!=Vt.end();j++)
		{
			if(*j!="#"&&*j!="$")
			{
				cout<<'\t';
				if(table[i][*j].right[0]!="error")
					cout<<Vn[i]<<"->";
				for(int k=0;k<table[i][*j].right.size();k++)
				{
					cout<<table[i][*j].right[k];
				}
				
			}
		}
		cout<<endl;
	}*/

}

void Grammar::show_stack(vector<string> s)
{
	cout<<"符号分析栈：";
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<'\t'<<" ";
	cout<<endl<<endl;
}

void Grammar::show_stack(vector<int> s)
{

	cout<<"状态分析栈：";
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<'\t'<<" ";
	cout<<endl;
}

void Grammar::show_vector(vector<string> v,int k)
{
	cout<<"输入串：";
	for(int i=k;i<v.size();i++)
		cout<<v[i]<<"\t";
	cout<<endl;
	cout<<endl;
}

void Grammar::union_item()
{
	for(int i=0;i<item_cluster.states.size();i++)
	{
		map<pair<int,int>,set<string>> lookingahead_join;//(产生式编号,圆点位置)->向前看符号集合

		for(auto j=item_cluster.states[i].items.begin();j!=item_cluster.states[i].items.end();j++)
		{
			pair<int,int> temp;
			temp={j->pro.num,j->point};

			if(lookingahead_join.find(temp)==lookingahead_join.end())
			{
				set<string> t={};
				lookingahead_join.insert({temp,t});
			}

			for(auto k=j->lookingahead_sign.begin();k!=j->lookingahead_sign.end();k++)
			{
				lookingahead_join[temp].insert(*k);
			}
		}
		State new_state;
		new_state=item_cluster.states[i];
		new_state.items.clear();

		for(auto j=lookingahead_join.begin();j!=lookingahead_join.end();j++)
		{
			Production temp_pdt=get_pdt(j->first.first);
			int point_loc=j->first.second;
			item new_item;
			new_item.left=temp_pdt.left;
			new_item.point=point_loc;
			new_item.pro=temp_pdt;
			new_item.lookingahead_sign=j->second;

			new_state.items.insert(new_item);
		}
		item_cluster.states[i]=new_state;

	}
}

void Grammar::get_table()
{
	for(int i=0;i<item_cluster.states.size();i++)
	{
		for(auto j=item_cluster.states[i].items.begin();j!=item_cluster.states[i].items.end();j++)
		{
			if(j->point==j->pro.right.size())//归约项目
			{
				pair<int,string> temp;
				for(auto k=j->lookingahead_sign.begin();k!=j->lookingahead_sign.end();k++)
				{					
					string num=std::to_string(j->pro.num);
					temp={item_cluster.states[i].state_id,*k};
					if(action_table.find(temp)!=action_table.end())
					{
						show_cluster();
						cout<<"该文法不是LR(1)文法："<<endl;
						if(action_table[temp][0]=='s')
						{
							cout<<"项目集I"<<item_cluster.states[i].state_id<<"移进移进-归约冲突！"<<endl;
						}
						else
						{
							cout<<"项目集I"<<item_cluster.states[i].state_id<<"移进归约-归约冲突！"<<endl;
						}
						exit(1);
					}
					action_table.insert({temp,"r"+num});
				}

				if(j->pro.left==start)
				{
					action_table[temp]="acc";
				}

			}
			else
			{
				string cur_string=j->pro.right[j->point];
				pair<int,string> temp;
				temp={item_cluster.states[i].state_id,cur_string};
				string num=std::to_string(item_cluster.shift_func[temp]);
				if(Vt.find(cur_string)!=Vt.end())//移进项目
				{			
					if(action_table.find(temp)!=action_table.end())
					{						
						if(action_table[temp]!="s"+num)
						{	
							show_cluster();
							cout<<"该文法不是LR(1)文法："<<endl;
							cout<<"项目集I"<<item_cluster.states[i].state_id<<"移进移进-归约冲突！"<<endl;
							exit(1);
						}
					}
					action_table.insert({temp,"s"+num});
				}
				else//待约项目
				{
					goto_table.insert({temp,item_cluster.shift_func[temp]});
				}
			}
		}
	}

}


