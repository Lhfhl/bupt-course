#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n];
	
	int i;
	for( i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	
	
	for( i = 0; i < n - 1; i++){
		int j;
		for( j = 0; j < n - 1; j++){
			if(a[j] < a[j+1]){
				int m = a[j];
				a[j] = a[j+1];
				a[j+1] = m;
			}
		}
	}
	
	int num,sum = 0;
	if(n % 2 == 0){
		num = n/2;
	}else{
		num = (n-1)/2;
	}
	
	for( i = 0; i < num; i++){
		if(a[i] % 2 == 0){
			sum += a[i] / 2;
		}else{
			sum = sum + (a[i]-1)/2;
		}
	}
	
	printf("%d",sum);
} 
