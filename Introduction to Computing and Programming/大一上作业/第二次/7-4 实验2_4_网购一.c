#include<stdio.h>

int main(){
	int a,b,c,d;
	int sum;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	sum = a+b+c+d; 
	
	if( sum < 20){
		sum += 10;
	}else if( sum >= 20&&sum <30){
		sum +=8;
	}else if( sum >= 30 && sum <40){
		sum +=5;
	}else if( sum >=40 ){
		sum += 0;
	}
	
	printf("%d",sum); 
	
} 
