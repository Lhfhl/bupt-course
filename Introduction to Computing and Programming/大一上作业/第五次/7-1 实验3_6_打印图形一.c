#include<stdio.h>

int main(){
	int l,c;	//���������� 
	
	scanf("%d%d",&l,&c);
	
	int j;
	int i;
	for( j = 0; j < l; j++){
			//��ӡ'*'�� 
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
	
	//��ӡ'*'�� 
	for( i = 0; i < c; i++){
		printf("|*****");
	}
	printf("|");
} 
