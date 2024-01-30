#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class expersion{
public:
    char left;
    string right;
};

int main()
{
    int stateNum;
    int actionNum;
    int gotoNum;
    vector<string> Actions;
    vector<char> Gotos;
    vector<vector<string> > table;
    vector<expersion> expersions;
    cout<<"��������ʽ���Կո�ָ����������֣�������ʽS->AaBֻ������S AaB��#����շ��ţ�����0��ֹ����"<<endl;
    char tmpLeft;
    string tmpRight;
    while (1){
        cin>>tmpLeft;
        if (tmpLeft=='0'){
            break;
        }
        cin>>tmpRight;
        expersion tmpExpersion;
        tmpExpersion.left=tmpLeft;
        tmpExpersion.right=tmpRight;
        expersions.push_back(tmpExpersion);

    }
    cout << "������״̬����" << endl;
    cin>>stateNum;
    cout << "������Action����" << endl;
    cin>>actionNum;
    cout<<"���������Action"<<endl;
    for (int i=0;i<actionNum;i++){
        string tmp;
        cin>>tmp;
        Actions.push_back(tmp);
    }
    cout << "������Goto����" << endl;
    cin>>gotoNum;
    cout<<"���������Goto"<<endl;
    for (int i=0;i<gotoNum;i++){
        char tmp;
        cin>>tmp;
        Gotos.push_back(tmp);
    }
    table.resize(stateNum);
    for (int i=0;i<stateNum;i++){
        table[i].resize(actionNum+gotoNum);
    }
    for (int i=0;i<stateNum;i++){
        for (int j=0;j<actionNum;j++){
            cout<<"������״̬"<<i<<"���ٷ���"<<Actions[j]<<"�Ķ���(���޶���������0)"<<endl;
            cin>>table[i][j];
        }
        for (int j=0;j<gotoNum;j++){
            cout<<"������״̬"<<i<<"����Ϊ"<<Gotos[j]<<"�Ķ���(���޶���������0)"<<endl;
            cin>>table[i][j+actionNum];
        }
    }
    string input;
    cout<<"��������Ҫ�����ķ��Ŵ�"<<endl;
    cin>>input;
    stack<int> stateStack;
    stack<string> symbolStack;
    stateStack.push(0);
    symbolStack.push("-1");
    cout<<"   ����ջ      ����      ���"<<endl;
    while (1){
        stack<int>tmpStateStack;
        stack<string>tmpSymbolStack;
        tmpStateStack=stateStack;
        tmpSymbolStack=symbolStack;
        vector<int>stateOutput;
        vector<string>symbolOutput;
        while (!tmpStateStack.empty()){
            stateOutput.push_back(tmpStateStack.top());
            tmpStateStack.pop();
        }
        while (!tmpSymbolStack.empty()){
            symbolOutput.push_back(tmpSymbolStack.top());
            tmpSymbolStack.pop();
        }
        reverse(stateOutput.begin(),stateOutput.end());
        reverse(symbolOutput.begin(),symbolOutput.end());
        for (int i=0;i<stateOutput.size();i++){
            cout<<stateOutput[i];
        }
        cout<<endl;
        for (int i=0;i<symbolOutput.size();i++){
            if (symbolOutput[i]!="-1"){
                cout<<symbolOutput[i];
            }else{
                cout<<'-';
            }
        }
        for (int i=0;i<9-symbolOutput.size();i++){
            cout<<" ";
        }
        cout<<input<<"   ";
        int symbolPosition;
        for (int i=0;i<actionNum;i++){
            if (input.find(Actions[i])==0){
                symbolPosition=i;
            }
        }
        if ((table[stateStack.top()][symbolPosition])[0]=='S'){
            stateStack.push(table[stateStack.top()][symbolPosition][1]-'0');
            symbolStack.push(Actions[symbolPosition]);
            input=input.substr(Actions[symbolPosition].size());
        }else if (table[stateStack.top()][symbolPosition][0]=='R'){
            int expersionPosition=table[stateStack.top()][symbolPosition][1]-'0';
            for (int i=0;i<expersions[expersionPosition].right.size();i++){
                stateStack.pop();
                symbolStack.pop();
            }
            symbolStack.push(string(1,expersions[expersionPosition].left));
            cout<<expersions[expersionPosition].left<<"->"<<expersions[expersionPosition].right;
            int gotoPosition;
            for (int i=0;i<gotoNum;i++){
                if (symbolStack.top()[0]==Gotos[i]){
                    gotoPosition=i;
                }
            }
            int tmpGoto=0;
            for (int i=0;i<table[stateStack.top()][gotoPosition+actionNum].size();i++){
                tmpGoto=tmpGoto*10;
                tmpGoto=tmpGoto+table[stateStack.top()][gotoPosition+actionNum][i]-'0';
            }
            stateStack.push(tmpGoto);
        }else if (table[stateStack.top()][symbolPosition]=="ACC"&&symbolStack.size()==2){
            cout<<"Accept!"<<endl;
            break;
        }
        cout<<endl;
    }
    return 0;
}
