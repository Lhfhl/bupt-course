#include<stdio.h>

int main(){
	int n;
	
	scanf("%d",&n);
	
	int num[n];
	
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	
	int j = 0, k = 0;
	
	for( i = 0; i < n - 1; i++){
		while(1){
			if(num[i] == num[i+1]){
				i++;
				k++;
			}else{
				break;
			}
		}
		k+=1;
		if( k > j ){
			j = k;
		}
//		i += k-1;
		k = 0;
	}
	if(n == 1){
		printf("1");
	}else{
		printf("%d",j);
	} 
	
} 
