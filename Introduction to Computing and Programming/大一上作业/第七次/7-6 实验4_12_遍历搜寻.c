#include<stdio.h>

int sum( int );
 
int main(){
	int a,b,c;
	
	scanf("%d%d%d",&a,&b,&c);
	
	int i,flag = 0,j = 0;
	for( i = a; i <= b; i++){
		int total = sum(i);
		if( i - total <= c && total - i <= c ){
			flag = 1;
			j++;
			 
			if( j % 5 == 1 ){
				printf("%d",i); 
			}else if( j % 5 == 0 ){
				printf("\t%d",i);
				printf("\n");
			}else{
				printf("\t%d",i);
			} 
		}
	}
	if( flag == 0 ){
		printf("There is no proper number in the interval.");
	}
}

int sum( int num ){
	int i;
	int sum = 0;
	for( i = 1; i < num; i++){
		if( num % i == 0 ){
			sum += i; 
		}
	}
	return sum;
}
