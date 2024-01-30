#include<stdio.h>

int main(){
	int n;
	
	scanf("%d",&n);
	
	int num[n];
	int nnum[n];
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	
	int j = 0;
	for( i = 0; i < n; i++){
		if( num[i] % 2 == 0 ){
			nnum[j] = num[i];
			j++;
		}
	}
	
	for( i = 0; i < n; i++){
		if( num[i] % 2 != 0){
			nnum[j] = num[i];
			j++;
		}
	}
	
	for( i = 0; i < n; i++){
		if( i != n - 1){
			printf("%d ",nnum[i]);
		}else{
			printf("%d",nnum[i]);
		} 
	}
}
