#include<stdio.h>

int main(){
	struct student{
		char name[21];
		int total;	
	};
	
	int num;
	scanf("%d",&num);
	struct student n[num];
	
	int i,j;
	for( i = 0; i < num; i++ ){
		struct student m;
		scanf("%s",&m.name);
		scanf("%d",&m.total);
		
		n[i] = m;
	}
	
	for( i = 0; i < num-1; i++ ){
		for( j = 0; j < num-1; j++ ){
			if( n[j].total < n[j+1].total ){
				struct student temp;
				temp = n[j+1];
				n[j+1] = n[j];
				n[j] = temp;
			}
			else if(n[j].total == n[j+1].total){
				if(strcmp(n[j].name,n[j+1].name) > 0){
					struct student temp;
					temp = n[j+1];
					n[j+1] = n[j];
					n[j] = temp;
				}
			}
		}
	}
	
	for( i = 0; i < num; i++ ){
		printf("Name:%s",n[i].name);
		printf("\ntotal:%d",n[i].total);
		printf("\n\n");
	}
}
