#include<stdio.h>

#define LEN 100

//�������� 
void distribute(int * bullets , int size , int number ) ;

int main()
{
    int bullets[LEN];
    int n,m,i;    
         
    scanf("%d",&n);    //����սʿ���� 
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d" , &bullets[i] ) ;//����ÿ��սʿ���г�ʼ���ӵ��� 
    }
    scanf("%d" , &m ) ;//��������Ĵ�����m>0) 
    distribute(bullets , n , m ) ;//���� 
    for( i = 0 ; i < n - 1 ; i++ )//����������� 
    {
        printf("%d " , bullets[i] ) ;
    }
    printf("%d\n" , bullets[i] ) ;
    
    return 0;    
}


/* ����������д�� */
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
