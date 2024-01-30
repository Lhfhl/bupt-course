#include<stdio.h>

int getString( char * source , char *strPtr[] ) ;

int main()
{
    char    str[100005];
    char    *strPtr[1005]={0};
    int        i, num ;
    
    gets(str);
    num = getString( str , strPtr ) ;
    for( i = 0 ; i < num ; i++ )
        puts(strPtr[i]);
    
    return 0;    
}

/* 请在这里填写答案 */
int getString( char * source , char *strPtr[] ){
	int j = 0;
	strPtr[j] = source; 
	while(*source != '\0'){
		if( *source == ' ' ){
			*source = '\0';
			if(*(source+1) != ' ' && *(source+1) != '\0'){
				j++;
				strPtr[j] = source+1;
			}
		}
		source++;		
	}
	return j+1;
} 
