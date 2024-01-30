#include<stdio.h>

int main(){
	int n,num;
	int cnt = 0;
	int r = 0;
	int j = 2;
	int isPrime = 1;
	
	scanf("%d",&n);
	
	int i;
	for( i = 0; i < n; i++ ){
		scanf("%d",&num);
		while( num != -1){
			j = 2;
			isPrime = 1;
			for( j = 2; j < num; j++){
				r = num%j;
				if( r == 0){
					isPrime = 0;
					break;
				}
			} 
			if( isPrime == 1 ){
				cnt++; 
			}
			scanf("%d",&num);
		}
		printf("%d\n",cnt);
		cnt = 0;
	}
}
