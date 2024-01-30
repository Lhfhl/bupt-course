#include<stdio.h>

int getDays(int,int) ;

int main()
{
    int    year, month ;
    
    scanf("%d%d",&year,&month);
    printf("There are %d days in month %d year %d.",getDays(year,month), month, year) ;

    return 0 ;    
}

/* 请在这里填写答案 */

int getDays(int year,int month){
	int day,flag = 0;
	
	if( ( ( year % 4 == 0 ) && ( year % 100 != 0 ) ) || year % 400 == 0 ){
		flag = 1;
	} 
	
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: day = 31;break;
		case 4:
		case 6:
		case 9:
		case 11: day = 30;break;
		case 2:{
			switch(flag){
				case 1: day = 29;break;
				case 0: day = 28;break;
			}
			break;
		}
	}
	return day;
} 
