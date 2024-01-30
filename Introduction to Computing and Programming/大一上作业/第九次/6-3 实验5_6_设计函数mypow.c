#include<stdio.h>

int mypow(int , int ) ;

int main()
{
    int x, n ;
    
    scanf("%d%d",&x,&n) ;
    printf("%d\n",mypow(x,n)) ;
                
    return 0;
}

/* 请在这里填写答案 */

int mypow(int x,int n){
	if( n == 0 ){
		return 1;
	}else{
		int i;
		int sum = 1;
		for( i = 0; i < n; i++){
			sum = sum * x;
		}
		
		return sum;
	} 
} 
