#include<stdio.h>

//�������ܣ����ֲ���
//�����������ֱ�Ϊ�����ҵ����飬���鳤�ȣ������ҵ�Ԫ��
//��������ֵ������ҵ����򷵻ظ�Ԫ���������е��±꣬���򷵻�-1 
int BinarySearch(int a[],int n,int key) ; 

int main()
{
    int    num[2000000] ; //�������Ƚϴ��������ĵ������޷�������ô����ڴ棬���С����ԡ�
    int        n , m, i;    
    int        key ;
    
    scanf("%d%d",&n,&m); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
        
    for( i = 0 ; i < m ; i++ ) 
    {
        scanf("%d",&key) ;
        printf("%d",BinarySearch(num,n,key)) ;
        if ( i != m - 1 ) printf(" ") ;
        else printf("\n") ;
    }
    return 0 ;
}


/* ����������д�� */
int BinarySearch(int a[],int n,int key){
	int middle,low = 0,high = n;
	while( low <= high ){
		middle = (low + high)/2;
		if(key == a[middle] ){
			return middle;
		}else if( key < a[middle] ){
			high = middle - 1;
		}else{
			low = middle + 1;
		}
	}
	return -1; 
} 

