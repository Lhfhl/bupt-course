#include<stdio.h>
#include<stdlib.h>

int main(){
	int **a,n ,m;
	int i,j;
	scanf("%d%d",&n,&m);
	a=(int **)malloc(sizeof(int *)*n);//��������Ϊn�Ķ�ָ̬������
	for(i=0;i<n;i++)
	a[i]=(int *)malloc(sizeof(int)*m);//��������Ϊm��һά��������
	
	for( i = 0; i < n; i++ ){
		for( j = 0; j < m; j++ ){
			scanf("%d",&a[i][j]);
		}
	} 
	
	for( i = 0; i < n; i++ ){
		for( j = 0; j < m; j++ ){
			if( j != m-1 ){
				printf("%d ",a[i][j]*(-10));
			} else{
				printf("%d",a[i][j]*(-10));
			}
		}
		printf("\n");
	} 
	
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);//�ͷŶ�̬�ڴ档
	
	
}



