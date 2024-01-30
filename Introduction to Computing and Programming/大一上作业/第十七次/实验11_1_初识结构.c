#include<stdio.h>

int main(){
	struct student{
		char name[21],id[21];
		int score[5];
		double average;
		int total;	
	};
	int num;
	scanf("%d",&num);
	struct student n[num];
	getchar();
	int k; 
	for( k = 0; k < num; k++ ){
		struct student m;
	
		gets(m.name);
		gets(m.id);
		int i,j,total = 0;
		for( i = 0; i < 5; i++ ){
			scanf("%d",&m.score[i]);
			total+=m.score[i];
		}
		m.total = total;
		m.average = total*1.0/5;
		
		for( i = 0; i < 4; i++ ){
			for( j = 0; j < 4; j++ ){
				if( m.score[j] < m.score[j+1] ){
					int temp = m.score[j+1];
					m.score[j+1] = m.score[j];
					m.score[j] = temp;
				}
			}
		}
		n[k] = m;
		getchar();
	} 
	
	for( k = 0; k < num; k++ ){
		struct student *ptr = &n[k];
		printf("Name:%s",ptr->name);
		printf("\nID:%s",ptr->id);
		printf("\nScore:");
		int i;
		for( i = 0; i < 4; i++){
			printf("%d ",ptr->score[i]);
		}
		printf("%d",ptr->score[4]);
		printf("\naverage:%.2lf total:%d",ptr->average,ptr->total);
		printf("\n\n");
	} 
	
}
