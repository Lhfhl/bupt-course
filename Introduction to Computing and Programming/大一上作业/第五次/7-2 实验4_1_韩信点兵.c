#include<stdio.h>

int main(){
	int n;
	
	scanf("%d",&n);
	
	int i;
	for( i = n; ; i++){
		if( i % 5 == 1 && i % 6 == 5 && i % 7 == 6 && i % 11 == 10 ){
			break;
		}
	}
	
	printf("%d",i);
}
