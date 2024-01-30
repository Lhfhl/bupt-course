#include<stdio.h>

int main(){
	long long n,nnum,a = 1,b = 1,y = 0;
	
	scanf("%lld",&n);
	
	if( n <= 2 ){
		printf("1");
	}else if( n > 2 ){
		int i;
		for( i = 0; i < n - 2; i++){
			
//			nnum = a + b;
//			a = b;
//			b = nnum;
			a = a % 101;
			b = b % 101;
			nnum = a + b;
			a = b;
			b = nnum; 
//			nnum = nnum % 101;
		}
//		y += a%101;
//		y += b%101;
		printf("%lld",nnum % 101);
	}
}
