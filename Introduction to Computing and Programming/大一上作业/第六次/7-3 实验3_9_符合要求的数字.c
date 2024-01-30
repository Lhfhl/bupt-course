#include<stdio.h>

int main(){
	int n,m,nnum = 0,num;
	int q; //±£¥Ê…Ã 
	
	scanf("%d%d",&n,&m);
	
	int i;
	for( i = 1; i <= n; i++){
		int j = i;
		q = j / m;
		while( j != 0 ){
			num = j % 10;
			nnum = num * num + nnum;
			j /= 10;
		}
//		printf("%d %d\n",q,nnum);
		if( nnum == q && i != n ){
			printf("%d\n",i);
		}else if( nnum == q && i == n ){
			printf("%d",i);
		}
//		num = 0;
		nnum = 0; 
	}
}
