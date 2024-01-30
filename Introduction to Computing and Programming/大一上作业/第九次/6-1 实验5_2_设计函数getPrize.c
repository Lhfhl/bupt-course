#include<stdio.h>

double getPrize(double x);

int main()
{
    double    x ;
    
    scanf("%lf",&x);
    printf("The prize is %.4f.\n",getPrize(x)) ;

    return 0 ;    
}

/* 请在这里填写答案 */

double getPrize(double x){
	double sum = 0;
	
	if( x > 100 ){
		sum += ( x - 100 ) * 0.01;
		x = 100;
	}
		
	if( x > 60 ){
		sum += ( x - 60 ) * 0.015;
		x = 60;
	}
	
	if( x > 40 ){
		sum += ( x - 40 ) * 0.03;
		x = 40; 
	}
	
	if( x > 20 ){
		sum += ( x - 20 ) * 0.05;
		x = 20;
	}
	
	if( x > 10 ){
		sum += ( x - 10 ) * 0.075;
		x = 10;
	}
	
	if( x <= 10 ){
		sum += x * 0.1;
	}
	
	return sum;
} 
