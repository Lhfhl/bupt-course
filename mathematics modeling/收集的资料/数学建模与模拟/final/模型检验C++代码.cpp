#include <bits/stdc++.h>
#define s 100 
#define maxnum 101    //三堆苹果的最大数量-1 
using namespace std;

int res [maxnum][maxnum][maxnum]={0}; //0：不确定  1：必胜  -1：必败 

int min(int a,int b) {return a<b?a:b;} //二者间取最小值函数 
	
int min3(int a,int b,int c) {return min(min(a,b),c);} //三者间取最小值函数 

int main()
{
	int i,j,k,i1,j1,k1,flag,minimum,big;
	
	res[0][0][0]=-1;
	
	for(i=0;i<maxnum;i++)
		for(j=0;j<maxnum;j++)
			for(k=0;k<maxnum;k++)
				if(res[i][j][k]==0)
				{
					//利用res函数判断当前状态必败还是必胜
					flag=1;
					for(i1=1;i1<=i&&i1<=s&&flag;i1++) if(res[i-i1][j][k]==-1) flag=0;
					for(j1=1;j1<=j&&j1<=s&&flag;j1++) if(res[i][j-j1][k]==-1) flag=0;
					for(k1=1;k1<=k&&k1<=s&&flag;k1++) if(res[i][j][k-k1]==-1) flag=0;
					minimum=min3(i,j,k); 
					for(big=1;big<=minimum&&flag;big++)if(res[i-big][j-big][k-big]==-1) flag=0;

					if(flag)res[i][j][k]=-1; //后继状态全为必胜，则其必败 
					else res[i][j][k]=1;     //后继状态存在必败情况，则其必胜 
				}
	
	//输出所有 t=(M,N,N) 的情况 
	for(i=0;i<maxnum;i++)
		for(j=0;j<maxnum;j++)
			//if(res[i][j][j]==-1)printf("res[%3d][%3d][%3d]=%d\n",i,j,j,res[i][j][j]);
			//cout<<i<<"\t"<<j<<"\t"<<res[i][j][j]<<endl;
			if(res[i][j][j]==-1)cout<<i<<"\t"<<j<<endl;
	cout<<endl<<endl<<endl;
	
	//输入用于取出任一结果 
	while(1)
	{
		cout<<"Input ( i,j,k ):";
		cin>>i>>j>>k;
		printf("res[%3d][%3d][%3d]=%d\n\n",i,j,k,res[i][j][k]);
	}
	
	return 0;
} 
