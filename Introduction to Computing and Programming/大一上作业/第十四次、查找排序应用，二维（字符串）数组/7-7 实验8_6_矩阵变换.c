#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int data[n][n];
	int i,j;
	for( i = 0; i < n; i++){
		for( j= 0; j < n; j++){
			scanf("%d",&data[i][j]);
		}
	}
	
	int sum1 = 0,sum2 = 0,k,l;

	for( i = 0; i < n - 1; i++ ){
		for( j = 0; j < n-1; j++){
			for( l = 0; l < n; l++){
				sum1 += data[j][l];
				sum2 += data[j+1][l];
			} 
			if( sum1 > sum2 ){
				for( k = 0; k < n; k++){
					int num = data[j][k]; 
					data[j][k] = data[j+1][k];
					data[j+1][k] = num; 
				}
			}
			sum1 = 0,sum2 = 0;
		}
	}
	
	for( i = 0; i < n; i++){
		for( j= 0; j < n; j++){
			if( j != n - 1){
				printf("%d ",data[i][j]);
			}else{
				printf("%d\n",data[i][j]);
			}
		}
	}
}
