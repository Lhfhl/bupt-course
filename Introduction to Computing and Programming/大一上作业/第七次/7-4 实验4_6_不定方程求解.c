#include<stdio.h>

int main(){
	int a,b,c;
	int cnt = 0;
	
	scanf("%d%d%d",&a,&b,&c);
	
	int i = 0,j = 0;
	for( i = 0;i * a + j * b <= c; i++){
		for( j =0;i * a + j * b <= c; j++){
			if( i * a + j * b == c){
				cnt++;
				break; 
			}
		}
		j = 0; 
	}
	
	printf("%d",cnt);
}
