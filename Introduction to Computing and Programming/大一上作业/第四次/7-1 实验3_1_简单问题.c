#include<stdio.h>

int main(){
	int n;
	int sum = 0,num,max,min;
	
	scanf("%d",&n);
	
	int i;
	
	scanf("%d",&num);
	max = num;
	min = num;
	sum += num;
	for( i = 0; i < n-1; i++){
		
		scanf("%d",&num);
		sum += num;
		if( num > max){
			max = num;
		}
		if( num < min){
			min = num;
		}
	}
	
	printf("%d %d %d",sum,max,min);
}
