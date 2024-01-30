#include<stdio.h>

int main(){
	int m,n;	//总人数和总的解题数
	
	scanf("%d%d",&m,&n);
	
	int i,j,k,l;
	int p = 0,e = 0;
	
	for( i = 0; i <= m; i++){
		for( j = 0; j <= m; j++){
			for( k = 0; k <= m; k++){
				for( l = 0; l <= m; l++){
					p += i;
					p += j;
					p += k;
					p += l;
					 
					e += 2*i;
					e += 3*j;
					e += 4*k;
					e += 1*l;
					
					if( p == m && e == n){
						printf("%d %d %d\n",i,j,k);
					}else{
						p = 0;
						e = 0;
					}
				} 
			}
		}
	}
}
