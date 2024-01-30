#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a,n;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int) * n);// 建立长度为n的动态整型数组
	
	int i;
	for( i = 0; i < n; i++ ){
		scanf("%d",a+i);
		*(a+i) = *(a+i) * (-1) * 10;
	}
	
	for( i = 0; i < n; i++ ){
		printf("%d ",*(a+i));
		
	}
	free(a);//释放动态内存。

}
