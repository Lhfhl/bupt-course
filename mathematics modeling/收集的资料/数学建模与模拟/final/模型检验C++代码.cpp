#include <bits/stdc++.h>
#define s 100 
#define maxnum 101    //����ƻ�����������-1 
using namespace std;

int res [maxnum][maxnum][maxnum]={0}; //0����ȷ��  1����ʤ  -1���ذ� 

int min(int a,int b) {return a<b?a:b;} //���߼�ȡ��Сֵ���� 
	
int min3(int a,int b,int c) {return min(min(a,b),c);} //���߼�ȡ��Сֵ���� 

int main()
{
	int i,j,k,i1,j1,k1,flag,minimum,big;
	
	res[0][0][0]=-1;
	
	for(i=0;i<maxnum;i++)
		for(j=0;j<maxnum;j++)
			for(k=0;k<maxnum;k++)
				if(res[i][j][k]==0)
				{
					//����res�����жϵ�ǰ״̬�ذܻ��Ǳ�ʤ
					flag=1;
					for(i1=1;i1<=i&&i1<=s&&flag;i1++) if(res[i-i1][j][k]==-1) flag=0;
					for(j1=1;j1<=j&&j1<=s&&flag;j1++) if(res[i][j-j1][k]==-1) flag=0;
					for(k1=1;k1<=k&&k1<=s&&flag;k1++) if(res[i][j][k-k1]==-1) flag=0;
					minimum=min3(i,j,k); 
					for(big=1;big<=minimum&&flag;big++)if(res[i-big][j-big][k-big]==-1) flag=0;

					if(flag)res[i][j][k]=-1; //���״̬ȫΪ��ʤ������ذ� 
					else res[i][j][k]=1;     //���״̬���ڱذ�����������ʤ 
				}
	
	//������� t=(M,N,N) ����� 
	for(i=0;i<maxnum;i++)
		for(j=0;j<maxnum;j++)
			//if(res[i][j][j]==-1)printf("res[%3d][%3d][%3d]=%d\n",i,j,j,res[i][j][j]);
			//cout<<i<<"\t"<<j<<"\t"<<res[i][j][j]<<endl;
			if(res[i][j][j]==-1)cout<<i<<"\t"<<j<<endl;
	cout<<endl<<endl<<endl;
	
	//��������ȡ����һ��� 
	while(1)
	{
		cout<<"Input ( i,j,k ):";
		cin>>i>>j>>k;
		printf("res[%3d][%3d][%3d]=%d\n\n",i,j,k,res[i][j][k]);
	}
	
	return 0;
} 
