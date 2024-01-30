#include<stdio.h>

int main(){
	int n,sum = 0;
	
	scanf("%d",&n);
	
	int i;
	for( i = 0; i < n; i++){
		if( i == 0 ){
			sum += 2;
		}else{
			sum += i+1;
		}	
	}
	printf("%d",sum);
}
