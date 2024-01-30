#include<stdio.h>

int main(){
	char a;
	
	int ch=0;
	int num=0;
	int blank=0;
	int oth=0;
	
	int i;
	
	scanf("%c",&a);
		
	while( a != '\n' && a != EOF){
		if( (a>= 'a' && a <= 'z') || ( a >= 'A' && a <= 'Z')){
			ch++;
		}else if( a >= '0' && a <= '9' ){
			num++;
		}else if( a == 32){
			blank++;
		}else{
			oth++;
		}
		scanf("%c",&a); 
	} 
		
	
	printf("%d %d %d %d",ch,blank,num,oth);
}
