#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class expersion{
public:
    char left;
    string right;
};

int main()
{
    int expersionCount=0;
    expersion expersions[128];
    set<char> first[128];
    set<char> follow[128];
    set<string> analysisTable[128][128];
    set<char> notEndSymbols;
    set<char> endSymbols;
    char tmpLeft;
    string tmpRight;
    cout<<"请输入表达式，以空格分隔左右两部分，例如表达式S->AaB只需输入S AaB，#代表空符号，输入0终止输入"<<endl;
    while (1){
        cin>>tmpLeft;
        if (tmpLeft=='0'){
            break;
        }
        cin>>tmpRight;
        expersions[expersionCount].left=tmpLeft;
        expersions[expersionCount].right=tmpRight;
        notEndSymbols.insert(tmpLeft);
        expersionCount++;
    }
    for (int i=0;i<expersionCount;i++){
        for (int j=0;j<(expersions[i].right).length();j++){
            set<char>::iterator it=notEndSymbols.find(expersions[i].right[j]);
            if (it==notEndSymbols.end()){
                endSymbols.insert(expersions[i].right[j]);
            }
        }
    }
    endSymbols.insert('$');
    cout<<"请逐行输入first集合，以空格分隔左右两部分，以,分隔集合内的终结符号，例如E (,id ，#代表空符号，输入0终止输入"<<endl;
    while (1){
        cin>>tmpLeft;
        if (tmpLeft=='0'){
            break;
        }
        cin>>tmpRight;
        for (int i=0;i<tmpRight.length();i++){
            if (tmpRight[i]!=','){
                first[tmpLeft].insert(tmpRight[i]);
            }
        }
    }
    cout<<"请逐行输入follow集合，以空格分隔左右两部分，以,分隔集合内的终结符号，例如E (,id ，#代表空符号，输入0终止输入"<<endl;
    while (1){
        cin>>tmpLeft;
        if (tmpLeft=='0'){
            break;
        }
        cin>>tmpRight;
        for (int i=0;i<tmpRight.length();i++){
            if (tmpRight[i]!=','){
                follow[tmpLeft].insert(tmpRight[i]);
            }
        }
    }
    for (int i=0;i<expersionCount;i++){
        set<char>::iterator it=notEndSymbols.find(expersions[i].right[0]);
        if (it==notEndSymbols.end()){
            if (expersions[i].right[0]!='#'){
                string cat="->";
                analysisTable[expersions[i].left][expersions[i].right[0]].insert(expersions[i].left+cat+expersions[i].right);
            }
            else{
                for (set<char>::iterator tmp=follow[expersions[i].left].begin();tmp!=follow[expersions[i].left].end();tmp++){
                    string cat="->";
                    analysisTable[expersions[i].left][*tmp].insert(expersions[i].left+cat+expersions[i].right);
                }
            }
        }else{
            for (set<char>::iterator tmp=first[expersions[i].right[0]].begin();tmp!=first[expersions[i].right[0]].end();tmp++){
                string cat="->";
                analysisTable[expersions[i].left][*tmp].insert(expersions[i].left+cat+expersions[i].right);
            }
        }
    }
    vector<char>output;
    cout<<"       ";
    for (set<char>::iterator b=endSymbols.begin();b!=endSymbols.end();b++){
        if (*b!='#'){
            output.push_back(*b);
            cout<<*b<<"         ";
        }
    }
    cout<<endl;
    for (set<char>::iterator a=notEndSymbols.begin();a!=notEndSymbols.end();a++){
        cout<<" "<<*a<<"   ";
        for (int i=0;i<output.size();i++){
            if (analysisTable[*a][output[i]].empty()){
                cout<<"          ";
            }
            for (set<string>::iterator c=analysisTable[*a][output[i]].begin();c!=analysisTable[*a][output[i]].end();c++){
                cout<<"  "<<*c;
                for (int i=0;i<10-(*c).length()-2;i++){
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    string input;
    cout<<"请输入需要分析的串"<<endl;
    cin>>input;
    stack<char> myStack;
    myStack.push('$');
    cout<<"请输入文法开始符号"<<endl;
    char startSymbol;
    cin>>startSymbol;
    myStack.push(startSymbol);
    string lastOutput="";
    cout<<"    栈        输入        输出    "<<endl;
    while (myStack.top()!='$'){
        cout<<"    ";
        if (myStack.top()==input[0]){
            stack<char> tmpStack=myStack;
            string outputStack="";
            while (!tmpStack.empty()){
                outputStack=outputStack+tmpStack.top();
                tmpStack.pop();
            }
            reverse(outputStack.begin(),outputStack.end());
            cout<<outputStack;
            for (int i=0;i<9-outputStack.length();i++){
                cout<<" ";
            }
            cout<<input<<'$';
            for (int i=0;i<11-input.length();i++){
                cout<<" ";
            }
            cout<<lastOutput;
            for (int i=0;i<9-lastOutput.length();i++){
                cout<<" ";
            }
            lastOutput="";
            myStack.pop();
            input=input.substr(1);
        }else{
            stack<char> tmpStack=myStack;
            string outputStack="";
            while (!tmpStack.empty()){
                outputStack=outputStack+tmpStack.top();
                tmpStack.pop();
            }
            reverse(outputStack.begin(),outputStack.end());
            cout<<outputStack;
            for (int i=0;i<9-outputStack.length();i++){
                cout<<" ";
            }
            cout<<input<<'$';
            for (int i=0;i<11-input.length();i++){
                cout<<" ";
            }
            char curStackTop=myStack.top();
            char curInputTop=input[0];
            if (input.length()==0){
                curInputTop='$';
            }
            string curStackInput="";
            for (set<string>::iterator tmp=analysisTable[curStackTop][curInputTop].begin();tmp!=analysisTable[curStackTop][curInputTop].end();tmp++){
                cout<<lastOutput;
                for (int i=0;i<9-lastOutput.length();i++){
                    cout<<" ";
                }
                lastOutput=*tmp;
                curStackInput=(*tmp).substr(3);
            }
            if (curStackInput=="#"){
                curStackInput="";
            }
            myStack.pop();
            for (int i=curStackInput.length()-1;i>=0;i--){
                myStack.push(curStackInput[i]);
            }
        }
        cout<<endl;
    }
    cout<<"    ";
    stack<char> tmpStack=myStack;
    string outputStack="";
    while (!tmpStack.empty()){
        outputStack=outputStack+tmpStack.top();
        tmpStack.pop();
    }
    reverse(outputStack.begin(),outputStack.end());
    cout<<outputStack;
    for (int i=0;i<9-outputStack.length();i++){
        cout<<" ";
    }
    cout<<input<<'$';
    for (int i=0;i<11-input.length();i++){
        cout<<" ";
    }
    cout<<lastOutput;
    for (int i=0;i<9-lastOutput.length();i++){
        cout<<" ";
    }
    return 0;
}

