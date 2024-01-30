#include <stdio.h>

void reverse(int n) ; 

int main()
{
    int     n;
         
    scanf("%d",&n);
    reverse(n) ;
    printf("\n");
    return 0;
}

/* 请在这里填写答案 */
void reverse(int n){
	if( n <= 9 ){
		printf("%d",n);
	}else{
		int m;
		
		m = n % 10;
		n /= 10;
		
		printf("%d",m);
		reverse(n);
	} 
} 
