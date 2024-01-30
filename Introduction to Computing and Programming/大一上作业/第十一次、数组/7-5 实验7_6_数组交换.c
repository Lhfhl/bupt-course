#include<stdio.h>

int main(){
	int n;
	
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
		int k = a[i];
		a[i] = a[b[i]];
		a[b[i]] = k;
	}
	
	for( i = 0; i < n; i++){
		if( i != n - 1){
			printf("%d ",a[i]);
		}else{
			printf("%d",a[i]);
		} 
	}
}
