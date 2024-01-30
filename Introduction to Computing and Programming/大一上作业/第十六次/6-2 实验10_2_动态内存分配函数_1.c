#include<stdio.h>
#include<stdlib.h>


int * create(int n) ;
void cal(int * array, int size) ;

int main()
{
    int * array , n , i ;
    
    scanf( "%d", &n );
    
    array = create(n) ;
    if ( array == NULL )
        return -1 ; //这里的return是因为没有获得内存而直接结束程序。
         
    cal( array, n) ;
    for ( i = 0 ; i < n ; i++ )
    {
        printf("%d" , *(array+i) ) ;
        if ( i == n - 1 ) printf("\n") ;
        else printf(" ") ;
    }     
    
    free(array) ;
    
    return 0;
}

/* 请在这里填写答案 */
int * create(int n){
	int *a;
	a = malloc(sizeof(int) * n);
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	return a; 
}

void cal(int * array, int size){
	int sum = 0;
	int max = array[0],min = array[0];
	int i;
	for( i = 0; i < size; i++){
		sum += array[i];
		if( array[i] > max ){
			max = array[i];
		}
		if( array[i] < min ){
			min = array[i];
		}
	}
	float average = sum*1.0/size;
	printf("%d\n",sum);
	printf("%.2f\n",average);
	printf("%d\n",max);
	printf("%d\n",min);
}
