#include<stdio.h>

int main(){
	int n,m;
	int k;
	
	scanf("%d",&n);
	
	int num[n];
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&num[i]);
	}
	
	scanf("%d",&m);
	
	int j,flag = 0;
	for( j = 0; j < m; j++){
		scanf("%d",&k);
		for( i = 0; i < n; i++){
			if(num[i] == k){
				flag = 1;
				if( m == 1){
					printf("NULL");
					break; 
				} else{
					if( i == n - 1 && j != m-1){
						printf("%d\n",num[n-2]);
						break;
					}else if( i == 0 && j != m-1){
						printf("%d\n",num[1]);
						break;
					}else if( j != m-1){
						printf("%d %d\n",num[i-1],num[i+1]);
						break;
					}else if(i == n - 1 && j == m-1){
						printf("%d",num[n-2]);
						break;
					}else if(i == 0 && j == m-1){
						printf("%d",num[1]);
						break;
					}else if(j == m-1){
						printf("%d %d",num[i-1],num[i+1]);
						break;
					} 
				}
			}
		}
		
		if( flag == 0 && j != m-1){
			printf("NULL\n");
		}else if( flag == 0 && j == m-1){
			printf("NULL");
		}
		flag = 0;
	}
}
