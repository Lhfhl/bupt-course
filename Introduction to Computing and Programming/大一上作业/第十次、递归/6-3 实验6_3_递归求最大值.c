#include <stdio.h>

int findMax(int n) ;

int main()
{   
    int n ; 
    
    scanf("%d", &n); 
    printf("%d\n" , findMax( n ) ) ; 
    
    return 0;
}

/* 请在这里填写答案 */
int findMax(int n){
	int max,num;
	
	if( n == 1 ){
		scanf("%d",&num);
		return num;
	}else{
		scanf("%d",&num);
		max = findMax(n-1);
		return num>max?num:max;
	} 
} 


