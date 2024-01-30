#include<stdio.h>

int main(){
	char str[100000];
	char temp[100000];
	int n;
	char *s = str;
	char *loc[100];
	loc[0] = str;
	scanf("%d",&n);
	getchar();
	int i;
	for( i = 0; i < n; i++ ){
		gets(temp);
		strcat(str,temp);
		while(*s!='\0'){
			s++;
		}
		s--;
		*s = '\0';
		loc[i+1] = s; 
	}
	strcpy(temp,loc[1]);
	printf("%s",temp);
}
