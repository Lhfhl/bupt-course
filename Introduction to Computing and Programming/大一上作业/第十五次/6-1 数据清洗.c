#include<stdio.h>

int getData(int source[] , int size , int target[] );

int dataCleaning(int n);

int main()
{
    int        source[110] , target[110];
    int        i , n , size ;
    
    scanf( "%d", &n ) ;
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d", &source[i] ) ; 
    size = getData( source , n, target ) ; 
    for ( i = 0 ; i < size - 1 ; i++ )
        printf( "%d " , target[i] ) ;
    printf( "%d\n" , target[i] ) ;
    
    return 0;    
}

/* ����������д�� */
int getData(int source[] , int size , int target[] ){
	int i,j = 0;
	for( i = 0; i < size; i++){
		if( dataCleaning(source[i]) ){
			target[j] = source[i];
			j++;
		}
	}
//	j++;
	return j;
} 

