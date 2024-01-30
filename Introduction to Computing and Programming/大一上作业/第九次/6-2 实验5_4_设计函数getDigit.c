#include<stdio.h>

int getDigit(long long n); 

int main()
{
    long long     n ;
    int            len ;
    
    scanf("%lld",&n);
    len = getDigit(n) ;
    if (len > 1)
        printf("The integer %lld has %d digits.\n",n, len) ;
    else
        printf("The integer %lld has %d digit.\n",n, 1) ;
    return 0 ;    
}

/* 请在这里填写答案 */

int getDigit(long long n){
	long long num;
	int i = 0;
	
	while( n != 0 ){
		n = n - n % 10;
		n /= 10;
		i++;	
	}
	
	return i;
}
