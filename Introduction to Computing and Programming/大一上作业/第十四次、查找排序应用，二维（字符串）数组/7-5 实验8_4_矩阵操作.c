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
	
	int a,b,sum = 0;
	scanf("%d%d",&a,&b);
	a-=1;
	b-=1;
	if(a-1 >= 0 && b-1 >= 0){
		sum+=data[a-1][b-1];
	}
	
	if( a-1 >= 0 && b+1 <= m-1){
		sum+=data[a-1][b+1];
	}
	
	if( a+1 <= n-1 && b-1 >=0){
		sum += data[a+1][b-1];
	}
	
	if( a+1 <= n-1 && b+1 <= m-1){
		sum += data[a+1][b+1];
	}
	
	if( a+1 <= n-1){
		sum += data[a+1][b];
	}
	
	if( a-1 >=0 ){
		sum += data[a-1][b];
	}
	
	if( b+1 <= m-1){
		sum += data[a][b+1];
	}
	
	if( b-1 >= 0){
		sum += data[a][b-1];
	}
	
	printf("%d",sum); 
}
