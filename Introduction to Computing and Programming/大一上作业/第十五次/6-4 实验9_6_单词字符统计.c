
#include<stdio.h>

#define        MAXLEN        110

int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}

/* 请在这里填写答案 */
int getResult( char word[] ){
	int numa[26] = {0};
    int numA[26] = {0};
	int i = 0;
	while( word[i] != '\0' ){
		if( word[i] >= 'a' && word[i] <= 'z' ){
            int cnt = word[i] - 'a';
            numa[cnt]++;
        }else{
            int cnt = word[i] - 'A';
            numA[cnt]++;
        }
		i++;
	} 
	int mina = numa[0] ,maxa = numa[0];
	int minA = numA[0] ,maxA = numA[0];
	for( i = 0; i <26; i++){
		if(numa[i] != 0){
			mina = numa[i];
			maxa = numa[i];
		}
		if(numA[i] != 0){
			minA = numA[i];
			maxA = numA[i];
		}
	}
	
	
	for( i = 0; i < 26; i++){
		if( mina >= numa[i] && numa[i] != 0){
			mina = numa[i];
		}
		if( maxa <= numa[i] ){
			maxa = numa[i];
		}
	}
    
    
	for( i = 0; i < 26; i++){
		if( minA >= numA[i] && numA[i] != 0){
			minA = numA[i];
		}
		if( maxA <= numA[i] ){
			maxA = numA[i];
		}
	}
    int min = mina,max = maxa;
    if( mina > minA && minA != 0){
        min = minA;
    }
    if( maxa < maxA ){
        max = maxA;
    }
	int r = max - min;
	if(isPrime(r)){
		return r;
	}else{
		return -1;
	}
} 

int isPrime( int n ){
	int i,flag = 0;
	if(n == 0 || n == 1){
		return 0;
	}
	for( i = 2; i < n; i++ ){
		if( n%i == 0 ){
			return 0;
		}
	}
	return 1;
}
 
