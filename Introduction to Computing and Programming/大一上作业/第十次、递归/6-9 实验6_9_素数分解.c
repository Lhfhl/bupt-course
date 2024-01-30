#include<stdio.h>

void printFactor( int, int ); 

int main()
{
    int a,b,i ;
    
    scanf( "%d%d", &a, &b );
    for( i = a ; i <= b ; i++ )
        printFactor( i , 1 ) ;    
    
    return 0;
}

/* 请在这里填写答案 */
void printFactor( int a, int b){
	int n = 2;
	if( b == 1 && a != 1){
		printf("%d=",a);
	}else if( a == 1 && b == 1){
		printf("1=1");
	}
	while( 1 ){
		if( a == 1 ){
			printf("\n");
			break; 
		}else{
			if( a % n == 0 && b == 1){
				b++;
				printf("%d",n);
				a /= n;
				printFactor(a,b);
				break;
			}else if( a % n == 0 && b != 1){
				b++;
				printf("*%d",n);
				a /= n;
				printFactor(a,b);
				break;	
			}else{
				n++;
			}
		}
	}
//	printf("\n"); 
} 

