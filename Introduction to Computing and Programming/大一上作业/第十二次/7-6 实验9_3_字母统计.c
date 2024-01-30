#include<stdio.h>

int main(){
	char c[101] = {'\0'};
	int numA[26] = {0};
	int numa[26] = {0};
	
	scanf("%s",c);
	
	int i = 0;
	while(c[i] != '\0'){
		if( c[i] >= 'A' && c[i] <= 'Z'){
			int l = (int)c[i] - 65;
			numA[l]++;
		}else if( c[i] >= 'a' && c[i] <= 'z'){
			int l = (int)c[i] - 97;
			numa[l]++;
		}
		i++;
	}
	
	for( i = 0; i < 26; i++){
		if(numA[i] != 0){
			char ch = (char)(i+65);
			printf("The character %c has presented %d times.\n",ch,numA[i]); 
		}
	}
	
	for( i = 0; i < 26; i++){
		if(numa[i] != 0){
			char ch = (char)(i+97);
			printf("The character %c has presented %d times.\n",ch,numa[i]); 
		}
	}
}
