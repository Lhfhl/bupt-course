#include<stdio.h>

int main(){
	char str[100] = "";
	
	scanf("%s",str);
	
	int i;
	for( i = 0; i < 100; i++){
		if( str[i] != '\0'){
			if( str[i] >= 'a' && str[i] <= 'z'){
				if( str[i] + 3 <= 122){
					str[i] += 3;
				}else{
					str[i] = str[i] - 23;
				}
			}else if( str[i] >= 'A' && str[i] <= 'Z'){
				if( str[i] + 3 <= 90){
					str[i] += 3;
				}else{
					str[i] = str[i] - 23;
				}
			}
		}
	}
	
	for( i = 0; i < 100; i++){
		if( str[i] != '\0'){
			printf("%c",str[i]);
		}
	} 
}
