#include<stdio.h>

void delcharfun(char *str,char ch);
 
int main()
{
    char    ch,str[110];
    
    scanf("%s",str);    //�����ַ��� 
    getchar();            //��ȡ�س����� 
    scanf("%c",&ch);    //�����ַ� 
    delcharfun(str,ch);    //ɾ�� 
    printf("%s\n",str);    //���ɾ������ 
    return 0;    
}

/* ����������д�� */
void delcharfun(char *str,char ch){
	while(*str != '\0'){
		if(*str == ch){
			char *temp = str;
			while(*str != '\0'){
				*str = *(str+1);
				str++;
			}
			str = temp;
		}else{
			str++;
		}
	}
}
