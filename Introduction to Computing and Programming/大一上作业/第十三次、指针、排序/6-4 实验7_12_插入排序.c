#include<stdio.h>

//������������ 
//����˵�������飬����������Ԫ�ظ��� 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;
    
    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}

/* ����������д�� */
void InsertSort(int a[],int n){
	int i;
	for( i = 1; i < n; i++){
		int j;
		for( j = 0; j < i; j++){
			if(a[i] < a[j]){
				int m = a[i];
				a[i] = a[j];
				a[j] = m;
			}
		}
		int k;
		for( k = 0; k < n; k++){
			if(k != n-1){
				printf("%d ",a[k]);
			} else{
				printf("%d\n",a[k]);
			}
		}
	} 
} 
