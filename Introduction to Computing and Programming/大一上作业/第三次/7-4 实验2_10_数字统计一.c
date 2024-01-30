#include<stdio.h>

int main(){
	int p3=0,p5=0,p7=0;
	int count;
	int num;
	
	scanf("%d",&num);
	
	while( num != 0 ){
		if( num % 3 == 0 && num % 5 != 0 && num % 7 != 0){
			p3++;
		}else if(num % 3 != 0 && num % 5 == 0 && num % 7 != 0){
			p5++; 
		}else if(num % 3 != 0 && num % 5 != 0 && num % 7 == 0){
			p7++;
		}
		count++;
		scanf("%d",&num);
	}
	double p;
	p = p3*100.0/count;
	printf("%.2lf%%\n",p);
	p = p5*100.0/count;
	printf("%.2lf%%\n",p);
	p = p7*100.0/count;
	printf("%.2lf%%",p);
}
