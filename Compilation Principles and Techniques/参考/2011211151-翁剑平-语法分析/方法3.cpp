#include<fstream>
#include<iomanip>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
using namespace std;
map<string,vector<string> > rule;         //存储文法规则
map<int,vector<string> > intToRule;       //文法编号 
map<vector<string> ,int>  ruleToInt;      //文法编号
map<string,set<string> > first;           //存储first集
map<string,set<string> > follow;          //存储follow集
string sArray[] = {"+", "-", "*","/","(",")","id","num","$","-1"};
set<string> VT(sArray, sArray + 9);       //文法的终结符 null表示空 
map<int,map<string ,int > > go;            //存储DFA转移表 
vector<set<vector<string> > > allItem;     //项目集规范族 
string inputString[]={"id","-","(","id","+","num",")","*","num","+","id","/","num","$"};     //第一个待检测分析字符串 
string inputString1[]={"id","+","num","*","$"};                                              //第二个待检测分析字符串 
map<int,map<string,vector<int> > > action;     //存储action表 
map<int, map<string ,int> > Goto;              //存储goto表 
void init_rule()                               //从rule.txt中读入文法
{
      ifstream ruleFile;
      ruleFile.open("rule.txt");
      string temp="",key="";
      ruleFile>>temp;
      while(temp!="-1")
      {
         int i=1;
         vector<string> content;
         while(temp!="-1")
         {
           if(i==1)
           {
              key=temp;
              i++;
              //cout<<"key"<<key;
           }
           else
           {
              content.push_back(temp);
           }
           ruleFile>>temp;
         } 
         rule.insert(pair<string,vector<string> >(key,content)); 
         ruleFile>>temp;
      }  
      ruleFile.close();
}

void printRule()              //输出文法
{ 
      map<string,vector<string> >::iterator   it;
      for(it = rule.begin();  it!=rule.end(); it++) 
      { 
         cout<<it->first<<"->";
         for(int i=0;i<it->second.size();i++)
         {
            if(i==it->second.size()-1)
               cout<<it->second[i];   
            else  
               cout<< std::left<<setw(3)<<it->second[i]<<" | ";
         } 
         cout<<endl;
      }  
}  
void printFirst()             //输出first集 
{
      map<string,set<string> >::iterator   it;
      for(it = first.begin();  it!=first.end(); it++) 
      { 
         cout<<it->first<<"  first集为： ";
         set<string> copy_set=it->second;
         set<string>::iterator copy_index;
         for (copy_index = copy_set.begin(); copy_index != copy_set.end(); copy_index++)
         {
            cout<<*copy_index<<" ";
         }
         cout<<endl;

      } 
      
       
} 
void printFollow()            //输出follow集 
{
      map<string,set<string> >::iterator   it;
      for(it = follow.begin();  it!=follow.end(); it++) 
      { 
         cout<<it->first<<"  follow集为： ";
         set<string> copy_set=it->second;
         set<string>::iterator copy_index;
         for (copy_index = copy_set.begin(); copy_index != copy_set.end(); copy_index++)
         {
            cout<<*copy_index<<" ";
         }
         cout<<endl;

      } 
      
       
} 
void getFirst()                //生成first集
{
     int flag=0; 
     map<string,vector<string> >::iterator   it;
     for(it = rule.begin();  it!=rule.end(); it++) 
     { 
           string temp_key=it->first;
           set<string> temp_set;
           first.insert(pair<string,set<string> >(temp_key,temp_set));
     }   
     while(flag==0)
     {
        flag=1;
        map<string,vector<string> >::iterator   it;
        map<string,set<string> >::iterator find_index;
        for(it = rule.begin(); it!=rule.end(); it++) 
        { 
           vector<string> content=it->second;
           
           string key=it->first;
           find_index=first.find(key);
           
           for(int i=0;i<content.size();i++)
           {
               string firstCh="";
               firstCh+=content[i][0];
              if (VT.find(firstCh) != VT.end())
              {
                  if(find_index->second.insert(firstCh).second)
                     flag=0;                  
              }
              else if(VT.find(content[i]) != VT.end())
              {
                  if(find_index->second.insert(content[i]).second)
                     flag=0;                  
              }
              else
              {
                  map<string,set<string> >::iterator first_index;
                  first_index=first.find(firstCh);
                  set<string> for_copy=first_index->second;
                  
                  set<string>::iterator copy_index;
                  for (copy_index = for_copy.begin(); copy_index != for_copy.end(); copy_index++)
                  {
                      if(*copy_index!="null")
                      {
                         if(find_index->second.insert(*copy_index).second)
                            flag=0;                      
                      }
                  }
              }       
           } 
           
        }           
     }    
}
void getFollow()            //生成follow集
{
     int flag=0; 
     map<string,vector<string> >::iterator   it;
     for(it = rule.begin();  it!=rule.end(); it++) 
     { 
           string temp_key=it->first;
           set<string> temp_set;
           if(temp_key=="E")
              temp_set.insert("$");
           follow.insert(pair<string,set<string> >(temp_key,temp_set));
     }
     while(flag==0)
     {
        flag=1;
        map<string,vector<string> >::iterator   it;
        map<string,set<string> >::iterator find_index;
        for(it = rule.begin(); it!=rule.end(); it++) 
        {
           vector<string> content=it->second;
           
           string key=it->first;
           find_index=follow.find(key);  
           for(int i=0;i<content.size();i++)
           {
               string sen=content[i];
               if (VT.find(sen) == VT.end()) 
               {
                  for(int j=0;j<sen.length();j++)
                  {
                      string for_com="";
                      for_com+= sen[j];
                      map<string,set<string> >::iterator current_index;
                      current_index=follow.find(for_com);
                      
                      string next="";
                      if(j!=sen.length()-1)
                      {
                         next+=sen[j+1];                  
                      }
                      
                      if(VT.find(for_com) == VT.end() ) 
                      {
                         if(j==sen.length()-1)
                         {
                            set<string> for_copy=find_index->second;
                            set<string>::iterator copy_index;
                             for (copy_index = for_copy.begin(); copy_index != for_copy.end(); copy_index++)
                             {
                                  if(current_index->second.insert(*copy_index).second)
                                     flag=0;                      
                             }                  
                         }
                         else if(VT.find(next) == VT.end()) 
                         {
                              map<string,set<string> >::iterator first_index;
                              first_index=first.find(next);
                              set<string> for_copy=first_index->second;
                              set<string>::iterator copy_index;
                              for (copy_index = for_copy.begin(); copy_index != for_copy.end(); copy_index++)
                              {
                                  if(*copy_index!="null")
                                  {
                                     if(current_index->second.insert(*copy_index).second)
                                       flag=0;                      
                                  }
                              }
                              if(j==sen.length()-2)
                              {
                                  if(for_copy.find("null") != for_copy.end()) 
                                  {
                                     set<string> for_copy=find_index->second;
                                     set<string>::iterator copy_index;
                                     for (copy_index = for_copy.begin(); copy_index != for_copy.end(); copy_index++)
                                     {

                                       if(current_index->second.insert(*copy_index).second)
                                         flag=0;                      
                                
                                     }                        
                                  }                
                              }
                         }   
                          else
                          {
                              if(current_index->second.insert(next).second)
                                     flag=0;
                          }            
                      }  
                  }              
               }   
           }  
        }
                   
     }       
}
set<vector<string> > produceSingleItem(set<vector<string> > S)         //生成某个活前缀的项目集 
{
         string blank="";
         set<vector<string> >::iterator it;
         int flag=1;
         while(flag==1)
         {
            flag=0;
            set<vector<string> > tempS=S;
            for(it=tempS.begin();it!=tempS.end();it++)
            {
                vector<string> tempV=*it;
                if(VT.find(tempV[0]) == VT.end())
                {
                   vector<string> tempR=rule.find(tempV[0])->second;
                   for(int i=0;i<tempR.size();i++)
                   {
                       vector<string> tempAI;
                       
                       if(VT.find(tempR[i]) != VT.end())    
                       {
                          tempAI.push_back(tempR[i]);                  
                       }
                       else
                       {
                          string tempCh="";
                          tempCh+=tempR[i][0];
                          tempAI.push_back(tempCh);

                       }
                       tempAI.push_back(tempV[0]);
                       tempAI.push_back(blank);
                       tempAI.push_back(tempR[i]);
                       if(S.insert(tempAI).second)
                         flag=1;
                   }                 
                }                                     
            }       
         }
         return S;               
}
vector<string> convert(vector<string> V)        //一条文法的跳转 
{
    vector<string> temp;
    string blank="";
    temp.push_back(blank);
    temp.push_back(blank);
    temp.push_back(blank);
    temp.push_back(blank);
    temp[1]=V[1];
    if(VT.find(V[3]) != VT.end())
    {
        temp[3]="";
        temp[0]="";
        temp[2]=V[2]+V[3];          
    } 
    else
    {
        if(V[3]!="")
        {
           temp[2]=V[2]+V[3][0];
           temp[3]=V[3];
           temp[3].erase(temp[3].begin());
           if(temp[3]!="")
             temp[0]+=temp[3][0];         
        } 
        else
           temp=V;
    }          
    return temp;
}
void printAllitem()            //输出项目集规范族 
{
     int count=0;
     for(count=0;count<allItem.size();count++)
     {
         set<vector<string> > tempI=allItem[count];
          set<vector<string> >::iterator it;
          cout<<endl<<count<<endl;
          for(it=tempI.begin();it!=tempI.end();it++)
          {
              vector<string> tempP=*it;

                  cout<<tempP[1]<<"->"<< std::left<<setw(3)<<tempP[2]<<"."<<tempP[3]<<"  "<<endl;    
                                                     
          }                                     
     }  
}
void getAllItems()          //生成项目集规范族 
{
     set<vector<string> > tempI;
     vector<string> F;
     string blank="";
     F.push_back("E"); 
     F.push_back("Z");
     F.push_back(blank);
     F.push_back("E");
     
     tempI.insert(F);
     allItem.push_back(tempI);
     int count=0;
     allItem[0]=produceSingleItem(allItem[0]);
     set<vector<string> >::iterator it;
    
     for(count=0;count<allItem.size();count++)
     {
         map<string,int> goItem;
         set<vector<string> > currentItem=allItem[count];
         
         for(it=currentItem.begin();it!=currentItem.end();it++)
         {
           
             
             set<vector<string> > tempConvert;
             vector<string> tempVC,tempOR;
             tempOR=*it;
             string firstCh="";
             firstCh+=tempOR[0];
             
             if(tempOR[0]!="")
             {
            
                string h=tempOR[0];
                
                tempVC=convert(tempOR);
                 
                tempConvert.insert(tempVC);
                tempVC.clear();
                
                for(it++;it!=currentItem.end()&&(*it)[0]==h;it++)
                {
                    
                    tempVC=convert(*it); 
                    tempConvert.insert(tempVC);    
                                                           
                }  
               it--;  
               
                
                tempConvert=produceSingleItem(tempConvert);
                int ishave=0;
                int i;
                for( i=0;i<allItem.size();i++)
                {
                     if(allItem[i]==tempConvert)
                     {
                         ishave=1;
                         
                         break;            
                     }        
                }
                
                if(ishave==0)
                {
                  allItem.push_back(tempConvert);
                  goItem.insert(pair<string,int>(firstCh,allItem.size()-1));
                }
                else
                {
                  goItem.insert(pair<string,int>(firstCh,i)); 
                }
             }                                                                    
         }     
         go.insert(pair<int ,map<string,int> >(count,goItem));
     }
}
void printGo()               //输出DFA 
{
    map<int,map<string ,int > >::iterator it;
    for(it=go.begin();it!=go.end();it++)
    {
        int num=it->first;
        map<string ,int > sec=it->second;
        map<string ,int >::iterator index;
        for(index=sec.begin();index!=sec.end();index++)
        {
            cout<< std::left<<setw(2)<<num<<" By "<< std::left<<setw(3)<<index->first<<" To "<<index->second<<endl;                                            
        }                                
    }
     
}
void getAnalyse()           //生成分析表 
{
     int i;
     for(i=0;i<allItem.size();i++)
     {
         set<string>::iterator it;
         map<string,vector<int> > actionI;
         for(it=VT.begin();it!=VT.end();it++)
         {
             vector<int> temp;
             actionI.insert(pair<string,vector<int> >(*it,temp));                                
         }    
         action.insert(pair<int,map<string,vector<int> > >(i,actionI));
         
         map<string,vector<string> >::iterator It;
         map<string,int > gotoI;
         for(It=rule.begin();It!=rule.end();It++)
         {
             int n=-1;
             gotoI.insert(pair<string,int>(It->first,n));                                  
         }
         Goto.insert(pair<int,map<string,int> >(i,gotoI)); 
     }
     for(i=0;i<allItem.size();i++)
     {
         set<vector<string> > tempI=allItem[i];
         set<vector<string> >::iterator it;
         for(it=tempI.begin();it!=tempI.end();it++)
         {
             if((*it)[0]=="")
             {
                if((*it)[1]=="Z"&&(*it)[2]=="E")
                 {
                    vector<int> acc;
                    acc.push_back(2);
                    acc.push_back(2);  
                    action.find(i)->second.find("$")->second=acc;                           
                 }
                 else //if(VT.find((*it)[2]) != VT.end())
                 {
                     
                     
                        set<string> tempF=follow.find((*it)[1])->second;
                        set<string>::iterator indexF;
                        vector<string> tempR;
                        tempR.push_back((*it)[1]);
                        tempR.push_back((*it)[2]);
                        int num=ruleToInt.find(tempR)->second;
                        vector<int> reduce;
                        reduce.push_back(1);
                        reduce.push_back(num); 
                        for(indexF=tempF.begin();indexF!=tempF.end();indexF++)
                       {
                         action.find(i)->second.find(*indexF)->second=reduce;                                                   
                        }                   
                     
                       
                }              
             }
            else if( VT.find((*it)[0]) != VT.end())
            {
              
                 int num=go.find(i)->second.find((*it)[0])->second;
                 vector<int> shift;
                 shift.push_back(0);
                 shift.push_back(num);
                 action.find(i)->second.find((*it)[0])->second= shift;
                  
                  
            }
                                           
         }
          map<string,vector<string> >::iterator itR;
          for(itR=rule.begin();itR!=rule.end();itR++)
          {
                 if(go.find(i)->second.find(itR->first)!=go.find(i)->second.end()) 
                 {
                    Goto.find(i)->second.find(itR->first)->second= go.find(i)->second.find(itR->first)->second;                                                             
                 }                                      
          }                          
     }
     
     
} 
void IntRuleInit()                 //给文法编号 
{
     map<string,vector<string> >::iterator it;
     int count=1;
     for(it=rule.begin();it!=rule.end();it++)
     {
        string left=it->first;
        vector<string> tempR=it->second;
        for(int i=0;i<tempR.size();i++)
        {
            vector<string> ru;
            ru.push_back(left);
            ru.push_back(tempR[i]);
            intToRule.insert(pair<int,vector<string> >(count,ru)); 
            ruleToInt.insert(pair<vector<string>,int >(ru,count)); 
            count++;   
        }                                     
     }
}
void printAnalyseList()               //输出分析表 
{
         cout<< std::left<<setw(3)<<" ";
         map<string,vector<int> >::iterator it;
         map<string,vector<int> > actionI=action.find(0)->second;
         for(it=actionI.begin();it!=actionI.end();it++)
         {
             cout<< std::left<<setw(6)<<it->first;                               
         }            
         map<string,int >::iterator It;
         map<string,int > gotoI=Goto.find(0)->second;
         for(It=gotoI.begin();It!=gotoI.end();It++)
         {
             cout<< std::left<<setw(6)<<It->first;                                 
         } 
         cout<<endl;
         map<int,map<string,vector<int> > >::iterator indexAc;
         map<int, map<string ,int> >::iterator indexGo;
         for(indexAc=action.begin();indexAc!=action.end();indexAc++)
         {
             int num=indexAc->first;
             cout<< std::left<<setw(3)<<num; 
             map<string,vector<int> > tempM=indexAc->second;
             map<string,vector<int> >::iterator indexM;
             for(indexM=tempM.begin();indexM!=tempM.end();indexM++)
             {
                 vector<int> tempV=indexM->second;
                 string op="";
                 if(tempV[0]==0)
                 {
                    op="s";
                    if(tempV[1]>=10)
                    {
                       op+="1";
                       tempV[1]-=10;            
                    }
                    char c='0'+tempV[1];
                    op+=c;
                 }
                 else if(tempV[0]==1)
                 {
                    op="r";
                    if(tempV[1]>=10)
                    {
                       op+="1";
                       tempV[1]-=10;            
                    }
                    char c='0'+tempV[1];
                    op+=c;  
                 } 
                 else if(tempV[0]==2)
                    op="acc";
                 cout<< std::left<<setw(6)<<op;                                                              
             }
             map<string,int> tempG=Goto.find(num)->second;
             map<string,int>::iterator indexG;
             for(indexG=tempG.begin();indexG!=tempG.end();indexG++)
             {
                  int N=indexG->second;
                  if(N!=-1)
                  cout<< std::left<<setw(6)<<N;                                                 
             }
              cout<<endl;                                                      
         }
}
string intToString(int n)          //int型数字转化为string型 
{
          std::stringstream ss;
          std::string str;
          ss<<n;
          ss>>str;
          return str;
} 
void analyseProcess(string inputString[])     //分析字符串的过程 
{
     stack<string> myStack;
     myStack.push(intToString(0));
     int ip=0;
     string S=myStack.top();
     string a=inputString[ip];
     do{
       S=myStack.top();
      
       a=inputString[ip];

       int b=atoi(S.c_str());
       vector<int> tempV=action.find(b)->second.find(a)->second;
       if(tempV.size()>0)
       {
                 if(tempV[0]==0)
                 {
                    myStack.push(a);
                    ip++;
                    
                    
                    string ss=intToString(tempV[1]);
                    
                    myStack.push(ss);
                    
                 }
                 else if(tempV[0]==1)
                 {
                      
                    vector<string> tempR=intToRule.find(tempV[1])->second;
                    int L;
                    if(VT.find(tempR[1]) != VT.end())
                      L=1;
                    else L=tempR[1].length();

                    for(int i=1;i<=L*2;i++)
                    {
                           
                       myStack.pop();
                      
                    }
                    
                   
                     
                    string S1=myStack.top();
                    
                    int Rnum=Goto.find(atoi(S1.c_str()))->second.find(tempR[0])->second;
                    myStack.push(tempR[0]);
                    myStack.push(intToString(Rnum));
                    cout<<tempR[0]<<"->"<<tempR[1]<<endl;
                 } 
                 else if(tempV[0]==2)
                  {
                     cout<<"accept!"<<endl;
                     return; 
                  } 
                  else
                  {
                     cout<<"不符合该文法"<<endl;
                     return; 
                  }                                                    
       } 
       else
       {
                     cout<<"不符合该文法"<<endl;
                     return; 
       }
     }while(1);
}
main()
{
      init_rule();
      cout<<"文法："<<endl; 
      printRule();
      IntRuleInit();
      getFirst();
      cout<<endl<<endl<<"FIRST集："<<endl;
      printFirst();
      cout<<endl<<endl<<"FOLLOW集："<<endl;
      getFollow();
      printFollow();
      
      getAllItems();
      cout<<endl<<endl<<"项目集："<<endl; 
      printAllitem();
      cout<<endl<<endl<<"DFA转移关系："<<endl; 
      printGo();
      getAnalyse();
      cout<<endl<<endl<<"分析表："<<endl;
      printAnalyseList();
      cout<<endl<<endl<<"测试第一个语句：";
      for(int i=0;inputString[i]!="$";i++)
	  	cout<<inputString[i];
      cout<<endl; 
      analyseProcess(inputString);
      cout<<endl<<endl<<"测试第二个语句："; 
      for(int i=0;inputString1[i]!="$";i++)
      	cout<<inputString1[i];
      cout<<endl;
      analyseProcess(inputString1);
      system("pause");
} 
