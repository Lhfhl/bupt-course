#include<stdio.h>

int main(){
	int l,c;	//行数和列数 
	
	scanf("%d%d",&l,&c);
	
	int j;
	int i;
	for( j = 0; j < l; j++){
			//打印'*'号 
		for( i = 0; i < c; i++){
			printf("|*****");
		}
		printf("|\n");
		
		for( i = 0; i < c; i++){
			printf("|  |  ");
		} 
		printf("|\n");
		
		for( i = 0; i < c; i++){
			printf("|--+--");
		}
		printf("|\n");
		
		for( i = 0; i < c; i++){
			printf("|  |  ");
		} 
		printf("|\n");
	}
	
	//打印'*'号 
	for( i = 0; i < c; i++){
		printf("|*****");
	}
	printf("|");
} 
