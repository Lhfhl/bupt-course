#include<stdio.h>

int main(){
	int a[200];
	
	int m,i = 0;
	scanf("%d",&m);
	 
	while( m != 0 ){
		a[i] = m;
		i++;
		scanf("%d",&m); 
	}
	
	int j,k,sum = 0;
	for( j = 0; j < i; j++){
		if( a[j] < 101 ){
			for( k = 0; k < i; k++){
				if( a[k] == a[j] * 2 ){
					sum++;
				}
			}
		}
	}
	printf("%d",sum);
}
