#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);
    
    if(p==NULL)    printf("NULL!\n");
    else    puts(p);
    
    return 0;
}

/* 请在这里填写答案 */
char *locatesubstr(char *str1,char *str2){
	int i = 0,j = 0,flag = 0,loc = 0;
	while(1){
		if( flag == 0 ){
			loc = i;
		}
		if( *(str1+i) == *(str2+j) ){
			i++;
			j++;
			flag = 1;
		}else{
			j = 0;
			flag = 0;
			i = loc+1;
		}
		if(*(str1+i) == '\0' && *(str2+j) != '\0'){
			char *c = NULL;
			return c;		
		}else if(*(str2+j) == '\0'){
			char *c = str1+loc;
			return c;
		}
	}
}
