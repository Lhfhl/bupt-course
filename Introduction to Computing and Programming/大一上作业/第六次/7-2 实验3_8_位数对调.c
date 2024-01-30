#include<stdio.h>

int main(){
	int num,nnum = 0,n;
	
	scanf("%d",&num);
	
	if( num % 10 == 0 ){
		printf("The number cannot be changed.");
	}else{
//		int t = 1,i=0;
//		while( t <= num ){
//			t *= 10;
//			i++;
//		}
//		t /= 10;
//		i--;
		
//		int j;
//		for( j = 0; j < i; j++)
		
		while( num != 0 ){
			n = num % 10;
			nnum = nnum * 10 + n;
//			t /= 10; 
			num /= 10;
		}
		printf("%d",nnum);
//		printf("%d %d",t,i); 
	}
} 
