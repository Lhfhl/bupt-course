#include<stdio.h>
#include<stdlib.h>

char ** create1(int n) ;
void create2( char ** strPtr , int n ) ;
void fill(char ** strPtr , int n) ;


int main()
{
    int        n, i;
    char**    strPtr ;

    scanf("%d", &n );
    strPtr = create1( n * 2 + 1 ) ;
    create2( strPtr ,  n * 2 + 1 ) ;
    fill(strPtr , n) ;

    for (i = 0; i < 2 * n + 1; i++)
    {
        printf("%s\n" , strPtr[i]);
    }
    
    for ( i = 0 ; i < n * 2 + 1 ; i++ )
        free(strPtr[i]) ;
    free(strPtr) ;

    return 0;
}

/* 请在这里填写答案 */
char ** create1(int n){
	char **c;
	c = (char **)malloc(sizeof(char*)*n);
	return c; 
}

void create2( char ** strPtr , int n ){
	int i;
	for( i = 0; i < n; i++ ){
		strPtr[i] = (char *)malloc(sizeof(char)*(n+1));
	}
} 

void fill(char ** strPtr , int n){
	int i,j;
	
	for( i = 0; i < n; i++ ){
		 strPtr[0][i] = ' ';
	}
	strPtr[0][n] = 'X';		strPtr[0][n+1] = '\0';
	
	strPtr[n][0] = 'X';
	for( i = 1; i < 2*n; i++ ){
		 strPtr[n][i] = ' ';
	}
	strPtr[n][2*n] = 'X';	strPtr[n][2*n+1] = '\0';
	
	for( i = 0; i < n; i++ ){
		 strPtr[2*n][i] = ' ';
	}
	strPtr[2*n][n] = 'X';		strPtr[2*n][n+1] = '\0';
	
	if( n >= 2 ){
		for( i = 0; i < n - 1; i++ ){
			for( j = 0; j < n-i-1; j++){
				strPtr[i+1][j] = ' ';
			}
			strPtr[i+1][n-i-1] = '/';
			for( j = n-i; j < n+i+1; j++){
				strPtr[i+1][j] = ' ';
			}
			strPtr[i+1][n+i+1] = '\\'; 
			strPtr[i+1][n+i+2] = '\0'; 
		}
		
		for( i = 0; i < n - 1; i++ ){
			for( j = 0; j < i+1; j++){
				strPtr[n+i+1][j] = ' ';
			}
			strPtr[n+i+1][i+1] = '\\';
			for( j = i+2; j < 2*n-i-1; j++){
				strPtr[n+i+1][j] = ' ';
			}
			strPtr[n+i+1][2*n-i-1] = '/'; 
			strPtr[n+i+1][2*n-i] = '\0'; 
		}
	} 
}
