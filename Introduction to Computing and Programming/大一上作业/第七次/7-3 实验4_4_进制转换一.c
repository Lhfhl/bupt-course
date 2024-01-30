#include<stdio.h>

int main(){
	int num,y,nnum = 0;
	int i = 0;
	
	scanf("%d",&num);
	
	while( num != 0 ){
		y = num % 10;
		int j;
		for( j = 0; j < i; j++){
			y = 2 * y;
		}
		nnum = y + nnum;
		num /= 10;
		i++;
	}
	printf("%d",nnum);
}
