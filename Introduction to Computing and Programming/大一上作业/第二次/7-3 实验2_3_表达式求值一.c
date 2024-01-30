#include<stdio.h>
#include<math.h>

int main(){
	double a,b,c,d;
	double m,n;
	
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
	n = b*c - d;
	
	if(fabs(n) <= 1e-15){
		printf("error");
	} else{
		m = a / n;
		printf("%.1lf", m);
	} 
}
