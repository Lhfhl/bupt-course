#include<stdio.h>

int    fuc(int n) ;

int main()
{
    int n ;
    
    scanf("%d",&n); 
    printf("%d\n",fuc(n));
  
    return 0 ;
}

/* ����������д�� */

int fuc(int n){
	int sum,a;
	
	if( n == 0 ){
		return 0;
	}else{
		a = n*n*n;
		return a+fuc(n-1);
	}
} 

