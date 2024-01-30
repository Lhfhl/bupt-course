#include<stdio.h>

int main(){
	int buffer[1024] = {0};
	int num;
	
	int i = 0;
	scanf("%d",&num);
	while( num != -1 ){
		buffer[i] = num;
		i++;
		scanf("%d",&num);
	}  
	
	int a[i];
	
	int j;
	for( j = 0; j < i; j++){
		a[j] = buffer[j];
	}
//	printf("\n");
	
	i = 0;
	scanf("%d",&num);
	while( num != -1 ){
		buffer[i] = num;
		i++;
		scanf("%d",&num);
	}  
	
	int b[i];
	
	for( j = 0; j < i; j++){
		b[j] = buffer[j];
//		printf("%d ",b[j]);
	}
	
	i = 0;
	for( j = 0; j < sizeof(a)/sizeof(a[0]); j++){
			if(b[i] == a [j]){
				i++;
			}else{
                if( i != 0 ){
                	j = j - i;
				} 
				i = 0;
			}
			
//			if( i + 1> sizeof(b)/sizeof(b[0]) ){
//				break; 
//			} 
	}
	if( i == sizeof(b)/sizeof(b[0]) ){
		printf("ListB is the sub sequence of ListA.");
	}else{
		printf("ListB is not the sub sequence of ListA.");
	}
} 
