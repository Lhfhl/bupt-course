#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int data[n][n];
	int a=0,b=0;
	
	int i,j=0;
	int flag = 1;
	data[a][b] = 1;
	
	for( i=2; i <= n*n; i++){
		if(flag == 1){
			a++;
			data[a][b] = i;
			if(b == 0){
				flag = 2;
			}else if(b == n - 1){
				flag = 4;
			}
		}else if(flag == 2){
			a--;
			b++;
			data[a][b] = i;
			if( a == 0 && b != n-1){
				flag = 3;
			}else if( b == n - 1){
				flag = 1;
			}else{
				flag = 2;
			}
		}else if(flag == 3){
			b++;
			data[a][b] = i;
			if(a == 0){
				flag = 4;
			}else if( a == n - 1){
				flag = 2;
			}
		}else if( flag == 4){
			a++;
			b--;
			data[a][b] = i;
			if( b ==0 && a!= n-1){
				flag = 1;
			}else if( a == n-1){
				flag= 3;
			}else{
				flag =4;
			}
		}
	} 
	
	int k,l;
	for( k = 0; k < n; k++){
		for( l = 0; l < n; l++){
			if( l!= n-1 ){
				printf("%d ",data[k][l]);
			} else{
				printf("%d\n",data[k][l]);
			}
		}
	}
}
