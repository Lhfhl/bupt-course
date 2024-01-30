#include "Grammar.h"
#include <iomanip>

int step=0;

void Grammar::eliminate_recursion()//消除左递归
{
	int pre_num=Vn.size();
	//消除直接左递归与间接左递归，最后再去除不可达符号
	for(int i=0;i<pre_num;i++)//对于所有非终结符
	{
		for(int j=0;j<i;j++)//去除所有形同 Ai->Aj的结构，再消除直接左递归
		{
			vector<Production> temp_P;//为每个非终结符构造新的产生式表
			for(int k=0;k<P[Vn[i]].size();k++)
			{
				int loc;
				if(Vt.find(P[Vn[i]][k].right[0])!=Vt.end())
				{
					loc=i+1;
				}
				else
				{
					loc=Vn_num[P[Vn[i]][k].right[0]];//获得产生式右侧第一个符号的顺序
				}
				
				if(loc<i)
				//产生式出现了Ai->Aj的结构,则将Aj的所有产生式代入到Ai的产生式中
				{
					string Aj=P[Vn[i]][k].right[0];
					vector<Production> temp_pdt=P[Aj];//获取Aj的所有产生式
					for(int m=0;m<temp_pdt.size();m++)//对于每个Aj的生成式
					{
						if(!(temp_pdt[m].right.size()==1&&temp_pdt[m].right[0]==Vn[i]))//去掉自环
						{
							for(int n=1;n<P[Vn[i]][k].right.size();n++)//代入到产生式中
							{
								temp_pdt[m].right.push_back(P[Vn[i]][k].right[n]);//将Aj后继部分加入
							}
							temp_P.push_back(temp_pdt[m]);
						}
					}

				}
				else
				{
					temp_P.push_back(P[Vn[i]][k]);//将该产生式加入新的产生式列表
				}
			}

			P[Vn[i]]=temp_P;

		}

		//消除直接左递归
		bool is_recursive=false;
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			if(P[Vn[i]][j].right[0]==Vn[i])
			{
				is_recursive=true;
				break;
			}
		}

		if(is_recursive==true)//产生式含有直接左递归 需要消除
		{
			vector<Production> temp_recursive;
			vector<Production> temp_nonrecursive;
			string new_temp=Vn[i]+"'";
			for(int j=0;j<P[Vn[i]].size();j++)
			{
				if(P[Vn[i]][j].right[0]==Vn[i])//包含左递归的产生式
				{
					Production temp_pdt;
					temp_pdt.right.insert(temp_pdt.right.begin(),
						P[Vn[i]][j].right.begin()+1,
						P[Vn[i]][j].right.end()
					);
					temp_recursive.push_back(temp_pdt);
				}
				else//无关者
				{
					temp_nonrecursive.push_back(P[Vn[i]][j]);
				}
			}

			//为原非终结符构造文法生成式
		
			P[Vn[i]].clear();
			/*P[Vn[i]].insert(P[Vn[i]].end(),
				temp_nonrecursive.begin(),
				temp_nonrecursive.end());*/
			for(int j=0;j<temp_nonrecursive.size();j++)
			{
				Production temp_pdt;
				temp_pdt.right.insert(temp_pdt.right.begin(),
					temp_nonrecursive[j].right.begin(),
					temp_nonrecursive[j].right.end()
				);
				if(!(temp_pdt.right.size()==1&&temp_pdt.right[0]=="#"))
				{
					temp_pdt.right.push_back(new_temp);
					P[Vn[i]].push_back(temp_pdt);
				}
			}
			//为新创建的非终结符构造文法生成式
			Vn_num.insert(make_pair(new_temp,Vn.size()));
			Vn.push_back(new_temp);
			P.insert(make_pair(new_temp,temp_recursive));
			Production temp_pdt_2;
			temp_pdt_2.right={"#"};
			P[new_temp].push_back(temp_pdt_2);
			/*for(int j=0;j<temp_recursive.size();j++)
			{
				Production temp_pdt;
				temp_pdt.right.insert(temp_pdt.right.begin(),
					temp_recursive[j].right.begin(),
					temp_recursive[j].right.end()
				);
				temp_pdt.right.push_back(new_temp);
				P[new_temp].push_back(temp_pdt);
				
			}*/
		}

	}

}

void Grammar::eliminate_public()
{
	map<string,vector<Production>> p;
	map<string,int> n;
	for(int i=0;i<Vn.size();i++)
	{
		vector<Production> temp;
		n.insert({Vn[i],0});
		p.insert({Vn[i],temp});
	}
	for(auto j=Vt.begin();j!=Vt.end();j++)
	{
		n.insert({*j,0});
		vector<Production> temp;
		p.insert({*j,temp});
	}
	for(int i=0;i<Vn.size();i++)
	{
		for(int j=0;j<Vn.size();j++)
		{
			n[Vn[j]]=0;
			p[Vn[j]].clear();
		}
		for(auto j=Vt.begin();j!=Vt.end();j++)
		{
			n[*j]=0;
			p[*j].clear();
		}
		for(int j=0;j<P[Vn[i]].size();j++)
		{
			n[P[Vn[i]][j].right[0]]++;
			p[P[Vn[i]][j].right[0]].push_back(P[Vn[i]][j]);
		}
		vector<Production> temp;
		for(auto j=n.begin();j!=n.end();j++)
		{	
			if(j->second<=1)
			{
				temp.insert(temp.end(),p[j->first].begin(),p[j->first].end());
			}
			else
			{
				string new_temp=Vn[i]+"'";//添加新的非终结符
				Vn_num.insert({new_temp,Vn.size()});
				Vn.push_back(new_temp);

				string front=j->first;
				Production pdt;
				vector<Production> qqntemp;
				
				P.insert({new_temp,qqntemp});//创建新映射

				pdt.right.push_back(front);
				pdt.right.push_back(new_temp);
				temp.push_back(pdt);

				for(int k=0;k<p[j->first].size();k++)
				{
					Production wobuxiangjuanle;
					wobuxiangjuanle.right.insert(
						wobuxiangjuanle.right.end(),
						p[j->first][k].right.begin()+1,
						p[j->first][k].right.end()
					);
					if(p[j->first][k].right.begin()+1==p[j->first][k].right.end())
						wobuxiangjuanle.right.push_back("#");
					P[new_temp].push_back(wobuxiangjuanle);

				}

			}
		}
		P[Vn[i]]=temp;
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

bool Grammar::is_id(string chs)
{
	if((chs[0]>='a'&&chs[0]<='z')||(chs[0]>='A'&&chs[0]<='Z')||chs[0]=='_')
		return false;
	for(int i=1;i<chs.size();i++)
	{
		if(!((chs[0]>='a'&&chs[0]<='z')||(chs[0]>='A'&&chs[0]<='Z')||chs[0]=='_'||(chs[0]<='9'&&chs[0]>='0')))
			return false;
	}
	return true;
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
								if(m!=k+1&&is_empty[Vn[m]]==false)
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
								if(is_empty[Vn[num]])
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
			for(int j=0;j<P[Vn[cur_sign]].size();j++)//对于该终结符的所有产生式
			{
				for(int k=0;k<P[Vn[cur_sign]][j].right.size();k++)
				{
					string cur_string=P[Vn[cur_sign]][j].right[k];
					if(k!=0&&!is_empty[Vn[k-1]])
					{
						break;
					}
					if(Vt.find(cur_string)==Vt.end())
						//非终结符处理：
					{
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
						else
						{
							if(!is_instack[Vn_num[cur_string]])
								s.push(Vn_num[cur_string]);//将该非终结符加入栈
							finish=false;

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
						if(is_empty[Vn[cur_sign]])
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
			if(finish)
				s.pop();
			is_finish[cur_sign]=finish;
		}
	}
	

}

void Grammar::get_analysis_table()//填写分析表
{
	eliminate_recursion();//消除直接和间接左递归
	eliminate_public();//提取左公因子
	remove_unreachable();//消除不可达状态
	get_FIRST();//获取FIRST集合
	get_FOLLOW();//获取FOLLOW集合
	for(int i=0;i<Vn.size();i++)
	{
		map<string,Production> temp;
		table.push_back(temp);
	}
	for(int i=0;i<Vn.size();i++)
	{
		string cur_n=Vn[i];
		for(auto j=Vt.begin();j!=Vt.end();j++)
		{
			string cur_t=*j;
			if(FIRST[cur_n].find(cur_t)!=FIRST[cur_n].end())
			{
				Production pdt;
				for(int k=0;k<P[Vn[i]].size();k++)
				{
					string First_sign=P[Vn[i]][k].right[0];
					if(Vt.find(First_sign)!=Vt.end())//是终结符
					{
						if(First_sign==*j)
						{
							pdt=P[Vn[i]][k];
						}
					}
					else if(FIRST[First_sign].find(*j)!=FIRST[First_sign].end())
					{
						pdt=P[Vn[i]][k];
					}
					
				}
				if(pdt.right.size()!=0)
				{
					table[i].insert(make_pair(cur_t,pdt));
				}
				else
				{
					pdt.right.push_back("error");
					table[i].insert(make_pair(cur_t,pdt));
				}
					
			}
			else if(FOLLOW[cur_n].find(cur_t)!=FOLLOW[cur_n].end())
			{
				Production pdt;
				for(int k=0;k<P[Vn[i]].size();k++)
				{
					if(is_emptyable(P[Vn[i]][k]))//若产生式可致空
					{
						pdt=P[Vn[i]][k];
					}
				}
				if(pdt.right.size()!=0)
				{
					table[i].insert(make_pair(cur_t,pdt));
				}
				else
				{
					pdt.right.push_back("error");
					table[i].insert(make_pair(cur_t,pdt));
				}
			}
			else
			{
				Production temp;
				temp.right.push_back("error");
				table[i].insert(make_pair(cur_t,temp));
			}

		}
	}
}

void Grammar::analyze_string(vector<string> token)
{
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
	vector<string> s;//分析栈
	int k=0;
	s.push_back("$");
	token.push_back("$");
	s.push_back(start);
	show_stack(s);
	show_vector(token,k);
	bool end=false;
	while(!s.empty()&&k<token.size()&&!end)
	{
		string cur_string=s[s.size()-1];
		if(token[k]==cur_string)
		{	
			if(cur_string=="$")
			{
				end=true;
				break;
			}
			s.pop_back();
			k++;		
			cur_string=s[s.size()-1];
		}
		else
		{
			s.pop_back();

			if(table[Vn_num[cur_string]][token[k]].right[0]=="#")
			{
				//无事发生
			}
			else if(table[Vn_num[cur_string]][token[k]].right[0]=="error")
			{
				cout<<"语法错误"<<endl;
				exit(1);
			}
			else
			{
				for(int i=table[Vn_num[cur_string]][token[k]].right.size()-1;i>=0;i--)
				{
					s.push_back(table[Vn_num[cur_string]][token[k]].right[i]);
				}
			}
		}
		//否则将该非终结符替换为其他表达式
		show_stack(s);
		show_vector(token,k);
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
			cout<<temp_vn<<" -> ";
			for(int k=0;k<P[temp_vn][j].right.size();k++)
			{
				cout<<P[temp_vn][j].right[k]<<" ";
			}
			cout<<endl;
		}
	}

	for(int i=0;i<FIRST.size();i++)
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
	}
}

void Grammar::show_stack(vector<string> s)
{
	cout<<"Step："<<step++<<endl;
	cout<<"分析栈：";
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<'\t'<<" ";
	cout<<endl;
}

void Grammar::show_vector(vector<string> v,int k)
{
	cout<<"输入串：";
	for(int i=k;i<v.size();i++)
		cout<<v[i]<<'\t'<<" ";
	cout<<endl;
	cout<<endl;
}


