#include<stdio.h>

int main(){
	int num;
	
	scanf("%d",&num);
	
	if( num < 1 || num > 10000 ){
		printf("%d  out of range",num);
	}else{
		int j = num;
		int i = 1;
		int nnum;
		
		while( j != 0 ){
			j /= 10;
			i *= 10;
		}
//		i /= 10;
		
		nnum = num*num % i; 
		if( nnum == num ){
			printf("Yes");
		}else{
			printf("No");
		}
//		printf("%d",i);
	}
}
