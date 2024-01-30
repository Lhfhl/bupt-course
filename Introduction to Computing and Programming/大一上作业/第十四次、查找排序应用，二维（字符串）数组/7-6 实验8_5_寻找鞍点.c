#include<stdio.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int data[n][m];

	int i,j;
	for( i = 0; i < n; i++){
		for( j = 0; j < m; j++){
			scanf("%d",&data[i][j]);
		}
	}
//	for( i = 0; i < n; i++){
//		for( j = 0; j < m-1; j++){
//			if(data[i][j] > data[i][j+1]){
//				int m = data[i][j];
//				data[i][j] = data[i][j+1];
//				data[i][j+1] = m;
//			}
//		}
//	}
//	
//	for( j = 0; j < m; j++){
//		for( i = 0; i < n-1; i++){
//			if(data[i][j] > data[i+1][j]){
//				int m = data[i][j];
//				data[i][j] = data[i+1][j];
//				data[i+1][j] = m;
//			}
//		}
//	}
	int flag = 0;
	for( i = 0; i < n; i++){
		for( j = 0; j < m; j++){
			flag = 0;
			int num = data[i][j];
			int k,l;
			for( k = 0; k < m; k++){
				if(k != j && num <= data[i][k]){
					flag = 1;
					break;
				}
			}
			for( l = 0; l < n; l++){
				if( l != i && num >= data[l][j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				break;
			} 
		}
		if(flag == 0){
			break;
		}
	} 
	if( flag == 0 ){
		printf("The saddle point is (%d,%d)=%d.",i,j,data[i][j]);
	}else{
		printf("There is no saddle point in the matrix."); 
	}
}
