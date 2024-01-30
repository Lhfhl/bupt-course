#include<stdio.h>

int main(){
	int n;
	
	scanf("%d",&n);
	
	float data[n][3];
	
	int i,j;
	for( i = 0; i < n; i++ ){
		for( j = 0; j < 3; j++){
			scanf("%f",&data[i][j]);
		}
	}
	
	float form[6][5];
	
	for( i = 0; i < 6; i++ ){
		for( j = 0; j < 5; j++){
			form[i][j] = 0;
		}
	}
	
	int k;
	for( k = 0; k < n; k++ ){
		int a = data[k][1] - 1;
		int b = data[k][0] - 1;
		form[a][b] += data[k][2];
	}
	
	float sum = 0;
	for( i = 0; i < 6; i++ ){
		for( j = 0; j < 4; j++){
			sum += form[i][j];
		}
		form[i][4] = sum;
		sum = 0;
	}
	
	for( j = 0; j < 5; j++){
		for( i = 0; i < 5; i++){
			sum += form[i][j]; 
		}
		form[5][j] = sum;
		sum = 0;
	}
	
	for( i = 0; i < 6; i++){
		for( j = 0; j < 5; j++){
			if( j != 4){
				printf("%.1f\t",form[i][j]);
			}else{
				printf("%.1f\n",form[i][j]);
			}
		}
	}
} 
