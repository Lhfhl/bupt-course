#include<stdio.h>

#define MAXN 20000

int RecurBinarySearch( int a[] , int key , int left , int right ) ;

int main()
{
    int        a[MAXN];//�������Ƚϴ��������ĵ������޷�������ô����ڴ棬���С����ԡ�
    int        n , m , i , key ;
    
    scanf("%d %d",&n , &m );    
    for( i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);
        
    for( i =0 ; i < m ; i++ )
    {
        scanf("%d",&key);
        printf( "%d" , RecurBinarySearch( a , key , 0 , n - 1 ) );
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ; 
    }

    return 0;
}

/* ����������д�� */
int RecurBinarySearch( int a[] , int key , int left , int right ){
	int middle;
	while( left <= right){
		middle = (left + right)/2;
		if(a[middle] == key){
			return middle;
		}else if( a[middle] > key){
			right = middle - 1;
			return RecurBinarySearch(a,key,left,right);
		}else{
			left = middle + 1;
			return RecurBinarySearch(a,key,left,right);
		}
	}
	return -1; 
} 

