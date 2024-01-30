#include<stdio.h>

int main(){
	char a;
	short b;
	int c;
	long d;
	long long e;
	float f;
	double g;
	
	scanf("%c%hd%d%ld%lld%f%lf",&a,&b,&c,&d,&e,&f,&g);
	
	printf("The 'char' variable is %c, it takes %zu byte.\n",a,sizeof(char));
	printf("The 'short' variable is %hd, it takes %zu bytes.\n",b,sizeof(short));
	printf("The 'int' variable is %d, it takes %zu bytes.\n",c,sizeof(int));
	printf("The 'long' variable is %ld, it takes %zu bytes.\n",d,sizeof(long));
	printf("The 'long long' variable is %lld, it takes %zu bytes.\n",e,sizeof(long long));
	printf("The 'float' variable is %f, it takes %zu bytes.\n",f,sizeof(float));
	printf("The 'double' variable is %lf, it takes %zu bytes.",g,sizeof(double));
}
