#include<stdio.h>

int main(){
	int m,n;	//分别代表头的个数和腿的个数 
	int r,c,d;		//分别为兔子数，鸡数，蜻蜓数 
	
	scanf("%d%d",&m,&n);
	
	int i,j,k;
	int h = 0,l = 0;
	 
	for( i = 0; i <= m; i++){
		for( j = 0; j <= m; j++){
			for( k = 0; k <= m; k++){
				h += i;
				h += j;
				h += k;
				
				l += 2*i;
				l += 4*j;
				l += 6*k;
				
				if( h == m && l == n){
					printf("%d %d %d\n",i,j,k);
				}else{
					h = 0;
					l = 0;
				} 
			}
		}
	} 
}
