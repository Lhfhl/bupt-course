#include <stdio.h>

//将n进制转换为m进制 
int numConvert(int,int,int) ; 

int main()
{
    int        number , m , n ;
    
    scanf("%d%d%d",&number,&n,&m);

    printf("%d\n",numConvert(number,n,m));
    return 0 ;
}


/* 请在这里填写答案 */
int numConvert(int number,int n,int m){
	int num = 0;
	int nnum = 0;
	
	if( n != 10 ){
		int k = 0;
		int l;
		while( number != 0 ){
			int i = number % 10;
			for( l = 0; l < k; l++){
				i *= n;
			}
			k++;
			num += i;
			number /= 10;	
		}
	}else{
		num = number;
	}
	
	int j = 1;
	int y = 0; 
	while( num >= j ){
		j *= m;
		y++;
	} 
	
	y--;
	j /= m;
	
	while( j != 0 ){
		int p = num /j;
		int x = y;
		while( x != 0 ){
			p *= 10;
			x--; 
		}
		y--;
		nnum += p;
		num = num % j;
		j /= m;
	}
	return nnum;
}


