#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a,n;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int) * n);// ��������Ϊn�Ķ�̬��������
	
	int i;
	for( i = 0; i < n; i++ ){
		scanf("%d",a+i);
		*(a+i) = *(a+i) * (-1) * 10;
	}
	
	for( i = 0; i < n; i++ ){
		printf("%d ",*(a+i));
		
	}
	free(a);//�ͷŶ�̬�ڴ档

}
