#include<stdio.h>

int main(){
	int n,sum = 0;
	
	scanf("%d",&n);
	
	int a[n],b[n];
	
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	
	for( i = 0; i < n; i++){
		scanf("%d",&b[i]);
	}
	
	for( i = 0; i < n; i++){
		sum += a[i] * b[i];
	}
	printf("%d",sum);
}
