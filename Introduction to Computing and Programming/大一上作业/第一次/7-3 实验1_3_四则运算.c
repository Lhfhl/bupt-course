#include<stdio.h>

int main(){
	double a,b,c,d;
	double result;
	
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
	result = (a+b)*(a-b)+c/d;
	
	printf("%lf",result);
	 
}
