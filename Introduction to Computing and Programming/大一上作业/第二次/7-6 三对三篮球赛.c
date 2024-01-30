#include<stdio.h>

int main(){
	int a,b;
	
	scanf("%d%d",&a,&b);
	
	if( (a > 22 || b > 22) || ( a >= 21 && b >= 21 )){
		printf("error");
	}else if( a == b && a < 21 && b < 21 ){
		printf("no result");
	}else if( a > b && b < 21){
		printf("A win");
	}else if( b > a && a < 21){
		printf("B win");
	}
}
