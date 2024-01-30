#include <stdio.h>

//判断一个数是否为完全数的函数
int isPerfect(int);

//打印完全数的函数 
void printPerfect(int);

int main()
{
    int i,a,b,count;
    
    scanf("%d%d",&a,&b);
    count = 0 ;//a,b两数间完全数的数量，初始化为0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //如果是完全数 
        {
            printPerfect(i) ;//打印该完全数 
            count ++ ;  //计数器加1 
        }        
    }
    printf("The total number is %d.\n",count);//输出a,b两数间完全数的数量 
    return 0 ;
}
/* 请在这里填写答案 */

int isPerfect(int n){
	int sum = 0;
	
	int i;
	for( i = 1; i*i < n; i++){
		if( n % i == 0 ){
			sum +=i;
			int j = n / i; 
			if( j < n ){
				sum += j;
			}
		}
	}
//	printf("%d %d \n",sum,n);
	if( sum == n ){
		return 1;
	}else{
		return 0;
	}
} 

void printPerfect(int n){
	printf("%d=",n);
	
	int i,flag = 0;
	for( i = 1; i < n; i++){
		if( n % i == 0 ){
			if( flag == 0 ){
				printf("%d",i);
			}else{
				printf("+%d",i);
			}
			flag = 1; 
		}
	}
	printf("\n"); 
} 

