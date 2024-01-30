#include<stdio.h>

int main(){
	char c[101] = {'\0'};
	char d[101] = {'\0'}; 
	scanf("%s",c);
	
	int i = 0,j = 0;
	while(i<101){
		if( c[i] == '(' || c[i] == ')'){
		d[j] = c[i];
		j++;	
		}
		i++; 
	}
//	printf("%s",d);
	
	int num = j;
	int k;
	for( k = 0; k < j; k++){
		if(d[k] == '('){
			int l;
			for( l = k+1; l < j; l++){
				if(d[l] == ')'){
					num -= 2;
					break;
				}
			}
		}
	}
	if(num == 0){
		printf("parentheses match!");
	}else{
		printf("parentheses do not match!");
	}
}
