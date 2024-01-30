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
map<string,set<string> > first;           //存储first集 
map<string,set<string> > follow;          //存储follow 
string sArray[] = {"+", "-", "*","/","(",")","id","num","null","$","-1"};      
set<string> VT(sArray, sArray + 9);       //文法的终结符 null表示空 
map<string,map<string ,string> > analyseList;     //存储分析表 
string inputString[]={"id","-","(","id","+","num",")","*","num","+","id","/","num","$"};   //第一个待检测分析字符串 
string inputString1[]={"id","+","num","*","$"};                                            //第二个待检测分析字符串
void init_rule()                         //从rule.txt中读入文法 
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
void deletL()                   //消除文法中的左递归 
{
      map<string,vector<string> >::iterator   it;
      vector<int> yes,no;
      int ch;
      for(it = rule.begin(),ch=0;  it!=rule.end(); it++,ch++) 
      { 
         string key=it->first;
         vector<string> content=it->second;
         //cout<<content[0]<<endl;
         yes.clear();
         no.clear();
         int i;
         for(i=0;i<content.size();i++)
         { 
            string temp="";
            temp+=content[i][0];
          //  cout<<temp<<endl;
          //  cout<<key<<endl;
            if(key==temp)
              yes.push_back(i);
             else
              no.push_back(i);
            
            
         }
         //cout<< yes.size()<<endl;
         if(yes.size()!=0)
         {
               char newch='A'+ch;
               string newKey="";
               newKey+=newch;
               it->second.clear();
               for(int k=0;k<no.size();k++)
               {
                  string newR=content[no[k]]+newKey; 
                  it->second.push_back(newR);                       
               }
               
               vector<string> newV;
               for(int k=0;k<yes.size();k++)
               {
                  string newt="";
                  for(int j=1;j<content[yes[k]].length();j++)
                  {
                    newt+=content[yes[k]][j];      
                  }
                  newt+=newKey;
                  newV.push_back(newt);
               }  
               newV.push_back("null");
               rule.insert(pair<string,vector<string> >(newKey,newV));
         }     
      }  
}
void printRule()               //输出文法 
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
void printFirst()              //输出first集 
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
void printFollow()             //输出follow集 
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
void getFirst()              //生成first集 
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
void getFollow()                 //生成follow集 
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
void getAnalyseList()                 //生成分析表 
{
     map<string,vector<string> >::iterator   it;
     for(it = rule.begin();  it!=rule.end(); it++)
     {
         string key=it->first;
         map<string,string> tempR;
         for(int j=0;sArray[j]!="-1";j++)
         {
            if(sArray[j]!="null")
            {
               string temp="";
               tempR.insert(pair<string,string >(sArray[j],temp));   
            }   
         }
         analyseList.insert(pair<string,map<string,string> >(key,tempR));  
     }
     for(it = rule.begin();  it!=rule.end(); it++) 
     {
         string key=it->first;
         for(int i=0;i<it->second.size();i++)
         {
             string tempR=it->second[i];
             if(tempR=="null")
             {
                set<string> followSet;
                followSet=follow.find(key)->second;
                set<string>::iterator index;
                for(index=followSet.begin();index!=followSet.end();index++)
                {
                   string tempCh=*index;
                   analyseList.find(key)->second.find(tempCh)->second=tempR;                                                        
                }                 
             }
             else if(VT.find(tempR) != VT.end())
             {
                   
                   analyseList.find(key)->second.find(tempR)->second=tempR;
             }
             else
             {
                  string tempF="";
                  tempF+=tempR[0];
                  
                  if(VT.find(tempF) != VT.end())
                  {      
                     analyseList.find(key)->second.find(tempF)->second=tempR;               
                  }
                  else
                  {
                      set<string> firstSet;
                      firstSet=first.find(tempF)->second;
                      set<string>::iterator index;
                      for(index=firstSet.begin();index!=firstSet.end();index++)
                      {
                         string tempCh=*index;
                         analyseList.find(key)->second.find(tempCh)->second=tempR;                                                        
                      }
                  }
             } 
         }       
     }   
}
void printAnalyseList()                 //输出分析表 
{
    map<string,map<string,string> >::iterator it;
    map<string,string> leftMap=analyseList.begin()->second;
    map<string ,string >::iterator indexLeft;
    cout<< std::left<<setw(3)<<" ";
    for(indexLeft = leftMap.begin();  indexLeft!=leftMap.end(); indexLeft++)
    {
           cout<< std::left<<setw(6)<<indexLeft->first;   
    }
    cout<<endl;
   for(it = analyseList.begin();  it!=analyseList.end(); it++)
   {
       string right=it->first;
       cout<< std::left<<setw(3)<<right;
       map<string,string> leftMap=it->second;
       map<string ,string >::iterator indexLeft;
       for(indexLeft = leftMap.begin();  indexLeft!=leftMap.end(); indexLeft++)
       {
           cout<<std::left<<setw(6)<<indexLeft->second;   
       }
       cout<<endl;
   }
     
}
void analyseProcess(string inputString[])           //检查待匹配的字符串 
{
    stack<string> myStack;
    myStack.push("$");
    myStack.push("E");
    string X;
    int ip=0;
    
    do{
       X=myStack.top();

       if(X=="$"||VT.find(X) != VT.end())
       {
           if(X==inputString[ip])
           {
              myStack.pop();
              ip++;                  
           }  
           else
           {
              cout<<"不符合该文法"<<endl;
              return; 
           }                
       }  
       else
       {
          string tempR=analyseList.find(X)->second.find(inputString[ip])->second;
          if(tempR=="")
          {
             cout<<"不符合该文法"<<endl;
             return;           
          }
          else
          {
              myStack.pop();
              if(tempR=="null")
              {}
              else if(VT.find(tempR) != VT.end())
              {
                myStack.push(tempR);                
              }
              else
              {
                 for(int i=tempR.length()-1;i>=0;i--)
                 {
                  string temp="";
                  temp+=tempR[i];
                  myStack.push(temp);    
                 }
              }
              cout<<X<<"->"<<tempR<<endl;
          }
       }    
    }while(X!="$");
    cout<<"accept!"<<endl;
}
main()
{
      init_rule();
      cout<<"原本的文法："<<endl;
      printRule();
      deletL();
      cout<<endl<<endl<<"消除左递归后的文法："<<endl;
      printRule();
      getFirst();
      cout<<endl<<endl<<"FIRST集："<<endl;
      printFirst();
      getFollow();
      cout<<endl<<endl<<"FOLLOW集："<<endl;
      printFollow();
      getAnalyseList();
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
      cout<<endl;
      system("pause");
} 
