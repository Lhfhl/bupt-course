#include<stdio.h>

int main(){
	int m,n,r,gcd,lcm;
	int flag = 1;
	
	scanf("%d%d",&m,&n);
	
	lcm = m*n;
	
	if( m < n ){
		r = n;
		n = m;
		m = r;
	}
	
	while( flag == 1 ){
		r = m % n;
		if( r == 0 ){
			gcd = n;
			flag = 0;
		}else{
			m = n;
			n = r;
		}
	}
	
	lcm = lcm / gcd;
	printf("%d %d",gcd,lcm); 
} 
