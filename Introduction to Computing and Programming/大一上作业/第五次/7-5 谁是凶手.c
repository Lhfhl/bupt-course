#include<stdio.h>
int main()
{
	int n;
	
	scanf("%d",&n);
	
	int a,b,c,d,e;
	int a1,b1,c1,d1,e1;
	
	scanf("%d  %d",&a,&a1);
	scanf("%d  %d",&b,&b1);
	scanf("%d  %d",&c,&c1);
	scanf("%d  %d",&d,&d1);
	scanf("%d  %d",&e,&e1);
	
	int sum=0;
	
	if(a==5&&a1==1) ++sum;
	if(a!=5&&a1==0) ++sum;
	if(b==5&&b1==1) ++sum;
	if(b!=5&&b1==0) ++sum;
	if(c==5&&c1==1) ++sum;
	if(c!=5&&c1==0) ++sum;
	if(d==5&&d1==1) ++sum;
	if(d!=5&&d1==0) ++sum;
	if(e==5&&e1==1) ++sum;
	if(e!=5&&e1==0) ++sum;
	
	if(sum==n)
	{
		printf("5");
	}  
	sum=0;
	
	if(a==6&&a1==1) ++sum;
	if(a!=6&&a1==0) ++sum;
	if(b==6&&b1==1) ++sum;
	if(b!=6&&b1==0) ++sum;
	if(c==6&&c1==1) ++sum;
	if(c!=6&&c1==0) ++sum;
	if(d==6&&d1==1) ++sum;
	if(d!=6&&d1==0) ++sum;
	if(e==6&&e1==1) ++sum;
	if(e!=6&&e1==0) ++sum;
	
	if(sum==n)
	{
		printf("6");
	}  
	sum=0;
	
	if(a==7&&a1==1) ++sum;
	if(a!=7&&a1==0) ++sum;
	if(b==7&&b1==1) ++sum;
	if(b!=7&&b1==0) ++sum;
	if(c==7&&c1==1) ++sum;
	if(c!=7&&c1==0) ++sum;
	if(d==7&&d1==1) ++sum;
	if(d!=7&&d1==0) ++sum;
	if(e==7&&e1==1) ++sum;
	if(e!=7&&e1==0) ++sum;
	
	if(sum==n)
	{
		printf("7");
	}  
	sum=0;
	
	if(a==8&&a1==1) ++sum;
	if(a!=8&&a1==0) ++sum;
	if(b==8&&b1==1) ++sum;
	if(b!=8&&b1==0) ++sum;
	if(c==8&&c1==1) ++sum;
	if(c!=8&&c1==0) ++sum;
	if(d==8&&d1==1) ++sum;
	if(d!=8&&d1==0) ++sum;
	if(e==8&&e1==1) ++sum;
	if(e!=8&&e1==0) ++sum;
	
	if(sum==n)
	{
		printf("8");
	}  
	sum=0;
	
	if(a==9&&a1==1) ++sum;
	if(a!=9&&a1==0) ++sum;
	if(b==9&&b1==1) ++sum;
	if(b!=9&&b1==0) ++sum;
	if(c==9&&c1==1) ++sum;
	if(c!=9&&c1==0) ++sum;
	if(d==9&&d1==1) ++sum;
	if(d!=9&&d1==0) ++sum;
	if(e==9&&e1==1) ++sum;
	if(e!=9&&e1==0) ++sum;
	
	if(sum==n)
	{
		printf("9");
	}  
	sum=0;
	
	return 0;
}
