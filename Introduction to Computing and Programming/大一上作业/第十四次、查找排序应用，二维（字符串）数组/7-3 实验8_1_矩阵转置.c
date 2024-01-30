#include<stdio.h>

int main(){
	int n,m;
	
	scanf("%d%d",&n,&m);
	
	int num[n][m];
	
	int i,j;
	for( i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d",&num[i][j]);
		}
	}
	
	int b[m][n];
	for( i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			b[j][i] = num[i][j]; 
		}
	}
	
	for( i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			if( j != n -1 ){
				printf("%d ",b[i][j]);
			}else{
				printf("%d\n",b[i][j]);
			}
		}
	}
}
