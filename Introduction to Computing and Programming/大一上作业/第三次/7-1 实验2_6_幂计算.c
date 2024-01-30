#include<stdio.h>

int main(){
	int x,y;
	int i;
	int sum;
	
	scanf("%d%d",&x,&y);
	
	sum = x;
	
	if( y == 0 ){
		sum = 1;
	}else{
		for( i = 0; i < y-1; i++){
			sum *=x;
		}
	}
	printf("%d",sum);
}
