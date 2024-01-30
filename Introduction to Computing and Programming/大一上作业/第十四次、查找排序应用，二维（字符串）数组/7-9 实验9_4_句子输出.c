#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int num[n];
	char data[n][30];
	int i,j;
	
	for( j = 0; j < n; j++){
		scanf("%s",data[j]);
	}
	for( j = 0; j < n; j++){
		scanf("%d",&num[j]);
	}
	
	for( j = 0; j < n; j++){
		printf("%s\n",data[num[j]]);
	}
}
