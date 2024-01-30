#include<stdio.h>

int main(){
	int n,m,y,nnum;
	
	scanf("%d",&n);
	m = n;
	
	if( n == 0 ){
		printf("Yes");
	}else{
		while( n != 0 ){
			y = n % 10;
			nnum = y + nnum * 10;
			n = n / 10;
		}
//		printf("%d %d",nnum,m);
		if( nnum == m ){
			printf("Yes");
		}else{
			printf("No");
		}
	}
}
