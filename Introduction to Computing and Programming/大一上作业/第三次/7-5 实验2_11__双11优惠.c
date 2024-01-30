#include<stdio.h>

int main(){
	int t;
	int n;
	int price;
	int sum = 0;
	
	scanf("%d",&t);
	
	int i;
	for( i = 0; i < t; i++){
		scanf("%d",&n);
		int j;
		for( j = 0; j < n; j++){
			scanf("%d",&price);
			sum += price;
		}
		
		if( sum >= 100 && sum < 200){
			sum -= 30;
		}else if( sum >= 200 && sum < 300){
			sum -= 70;
		}else if( sum >= 300 && sum < 400){
			sum -= 110;
		}else if( sum >= 400){
			sum -= 160;
		}
		
		printf("%d\n",sum);
		sum = 0; 
	}
}
