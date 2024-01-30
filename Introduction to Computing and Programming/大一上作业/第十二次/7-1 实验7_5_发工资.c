#include<stdio.h>

int main(){
	int s;
	int cnt[7] = {0};
	int mian_zhi[7] = {100,50,20,10,5,2,1};
	scanf("%d",&s);
	
	if( s >= 100 ){
		while( s >= 100 ){
			s -= 100;
			cnt[0]++;
		}
	}
	
	if( s >= 50 ){
		while( s >= 50 ){
			s -= 50;
			cnt[1]++;
		}
	}
	
	if( s >= 20 ){
		while( s >= 20 ){
			s -= 20;
			cnt[2]++;
		}
	}
	
	if( s >= 10 ){
		while( s >= 10 ){
			s -= 10;
			cnt[3]++;
		}
	}
	
	if( s >= 5 ){
		while( s >= 5 ){
			s -= 5;
			cnt[4]++;
		}
	}
	
	if( s >= 2 ){
		while( s >= 2 ){
			s -= 2;
			cnt[5]++;
		}
	}
	
	if( s >= 1 ){
		while( s >= 1 ){
			s -= 1;
			cnt[6]++;
		}
	}
	
	int i; 
	for( i = 0; i < 7; i++){
		if(cnt[i] != 0){
			printf("%d:%d\n",mian_zhi[i],cnt[i]);
		}
	}
} 
