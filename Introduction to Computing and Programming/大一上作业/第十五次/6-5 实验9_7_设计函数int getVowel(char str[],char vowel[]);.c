#include <stdio.h>
#include<stdio.h>

//��ֻ����Сд��ĸ���ַ���str�е�Ԫ����ĸ���Ƶ��ַ�����vowel,������Ԫ���ַ��ĸ�����
int getVowel(char str[],char vowel[]);
 
int main()
{
    char    vowel[101] , str[101];//ÿ�����鶼����Ҫ101���ֽ� 
    int        len ;
    
    scanf("%s",str);    //�����ַ��� 
    len = getVowel(str,vowel);    //���� 
    if ( len > 0 ) printf("%d %s\n", len , vowel);    //������ƺ��� 
    else printf("%d\n", len);//��������� 
    
    return 0;    
}

/* ����������д�� */
int getVowel(char str[],char vowel[]){
	int i = 0, j = 0;
	while(str[i] != '\0'){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
			vowel[j] = str[i];
			j++;
		}
		i++;
	}
	return j;	
}
