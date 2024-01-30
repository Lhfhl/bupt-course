#include<stdio.h>

int main(){
	int num,n;
	int t = 10;
	
	scanf("%d",&num);
	
	int i = 0;
	while( t <= num ){
		t *= 10;
		i++;
	}
	t /= 10;
	i++;
	
	int j;
	for( j = 0; j < i; j++ ){
		if( num % t == num ){
			if( j == i - 1 ){
				printf("0\n");
			}else{
				printf("0 ");
			}
			t /= 10;
		}else{
			n = num/t; 
			num -= t*n;
			t /= 10;
			if( j == i - 1 ){
				printf("%d\n",n);
			}else{
				printf("%d ",n);
			} 
		}
	} 
//	printf("%d %d",t,i); 
}
