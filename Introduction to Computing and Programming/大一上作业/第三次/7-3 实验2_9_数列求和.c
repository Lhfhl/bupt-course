#include<stdio.h>
int main()
{
	long long n,an=0,sum=0;
	long long j=1,i=1;
	
	scanf("%lld",&n);
	
	if( n <= 2){
		sum = 0; 
	} 
	else{
	   for(j=3;j<=n;j++){
		    for(i=3;i<=n-j+3;i++)
			{
		        an += i*(i-1)*(i-2);
		    }
	    sum += an;
	    an=0;
	    }
	 	printf("%lld",sum);
	}
	 	return 0;
}
