#include<stdio.h>

//���ַ���str�е����ݷ����ӡ�ĺ��� 
void reversePrint(char str[]) ;

int main()
{
    char    s[100] ;
    
    scanf( "%s" , s );    
    reversePrint(s) ;

    printf("\n") ;
    
    return 0;
}

/* ����������д�� */
void reversePrint(char str[]){
	if( str[0] != '\0' ){
	 	int i = 1;
	 	char s[100] = {'\0'}; 
		while( str[i] != '\0' ){
			s[i-1] = str[i];
			i++;
		}
		if( i != 1 ){
			reversePrint(s);
		} 
		printf("%c",str[0]);
	} 
} 
