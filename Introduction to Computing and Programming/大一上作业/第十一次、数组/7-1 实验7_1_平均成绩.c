#include<stdio.h>

int main(){
	int n,sum = 0;
	double average;
	
	scanf("%d",&n);
	
	int score[n];
	
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&score[i]);
	}
	
	for( i = 0; i < n; i++){
		sum += score[i];
	}
	
	average = (double)sum / n;
	
	printf("%.2lf",average);
} 
