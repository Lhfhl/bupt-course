#include<stdio.h>
#include<math.h>

int main(){
	double x,sum = 0;
	double nnum;
	
	scanf("%lf",&x);
	
	double i;
	for( i = 0; ; i++){
		double j = 1,jie = 1,mi = 1;
		for( j = 0; j < i; j++){
			int k = j+1;
			jie *= k;
			mi *= x;
		}
		double a = mi/jie;
		if(fabs(a)<1e-8){
			printf("%.4lf",sum);
			break;
		}else{
			sum += a;
		}
//		printf("%lf %lf %lf %lf\n",sum,mi,jie,a);
	}
}
