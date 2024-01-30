#include<stdio.h>

#define LEN 100

//调整函数 
void distribute(int * bullets , int size , int number ) ;

int main()
{
    int bullets[LEN];
    int n,m,i;    
         
    scanf("%d",&n);    //读入战士总数 
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d" , &bullets[i] ) ;//读入每个战士手中初始的子弹数 
    }
    scanf("%d" , &m ) ;//读入调整的次数（m>0) 
    distribute(bullets , n , m ) ;//调整 
    for( i = 0 ; i < n - 1 ; i++ )//输出调整后结果 
    {
        printf("%d " , bullets[i] ) ;
    }
    printf("%d\n" , bullets[i] ) ;
    
    return 0;    
}


/* 请在这里填写答案 */
void distribute(int * bullets , int size , int number ){
	int i,k;
	int a[size]; 
	
	for( k = 0; k < number; k++){
		int j;
		int *ptr = bullets;
		for( i = 0; i < size; i++){
			if(*bullets%2 != 0){
				(*bullets)++;
			}
			a[i] = (*bullets)/2;
			*bullets /= 2;
			bullets++;
		}
		bullets = ptr;
		for( j = 0; j < size; j++){
			if( j == size - 1 ){
				*ptr += a[j]; 
			}else{
				*(bullets+1) += a[j]; 
				bullets++;
			}
		}
		bullets = ptr;
	} 
}
