#include <stdio.h>

//�ж�һ�����Ƿ�Ϊ��ȫ���ĺ���
int isPerfect(int);

//��ӡ��ȫ���ĺ��� 
void printPerfect(int);

int main()
{
    int i,a,b,count;
    
    scanf("%d%d",&a,&b);
    count = 0 ;//a,b��������ȫ������������ʼ��Ϊ0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //�������ȫ�� 
        {
            printPerfect(i) ;//��ӡ����ȫ�� 
            count ++ ;  //��������1 
        }        
    }
    printf("The total number is %d.\n",count);//���a,b��������ȫ�������� 
    return 0 ;
}
/* ����������д�� */

int isPerfect(int n){
	int sum = 0;
	
	int i;
	for( i = 1; i*i < n; i++){
		if( n % i == 0 ){
			sum +=i;
			int j = n / i; 
			if( j < n ){
				sum += j;
			}
		}
	}
//	printf("%d %d \n",sum,n);
	if( sum == n ){
		return 1;
	}else{
		return 0;
	}
} 

void printPerfect(int n){
	printf("%d=",n);
	
	int i,flag = 0;
	for( i = 1; i < n; i++){
		if( n % i == 0 ){
			if( flag == 0 ){
				printf("%d",i);
			}else{
				printf("+%d",i);
			}
			flag = 1; 
		}
	}
	printf("\n"); 
} 

