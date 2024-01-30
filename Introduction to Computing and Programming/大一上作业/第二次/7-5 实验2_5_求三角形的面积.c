#include<stdio.h>
#include<math.h>

int main(){
	int a,b,c;
	double s;
	double area;
	
	scanf("%d%d%d",&a,&b,&c);
	
	s = (a+b+c)/2.0;
	
	if(a+b>c&&a+c>b&&b+c>a){
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		
		printf("%.3lf",area);	
	}else{
		printf("The edges cannot make up of a triangle.");
	}
}
