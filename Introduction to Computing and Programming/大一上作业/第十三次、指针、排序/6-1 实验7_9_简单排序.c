#include<stdio.h>

void bubbleSort(int a[],int n);

//�������������Ԫ�� 
void outputData(int data[],int elementCount) ;

int main()
{
    int n,i,num[10010] ;
    
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    bubbleSort(num,n) ; 
    outputData(num,n) ;
    return 0 ;
}


/* ����������д�� */
void bubbleSort(int a[],int n){
	int i;
	for( i = 0; i < n-1; i++){
		int j;
		for( j = 0; j < n-1; j++){
			if(a[j] > a[j+1]){
				int m = a[j];
				a[j] = a[j+1];
				a[j+1] = m; 
			}
		}
	}
}

void outputData(int data[],int elementCount){
	int i;
	for( i = 0; i < elementCount; i++){
		if( i != elementCount - 1){
			printf("%d ",data[i]);
		}else{
			printf("%d\n",data[i]);
		}
	} 
} 
