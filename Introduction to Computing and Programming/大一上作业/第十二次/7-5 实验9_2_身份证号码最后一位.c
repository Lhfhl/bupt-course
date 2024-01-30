#include<stdio.h>

int main(){
	int n;
	char c[19];
	int num[18];
	scanf("%d",&n);
	int i;
	int j;
	int sum = 0;
	for( j = 0; j < n; j++){
		scanf("%s",c);
		for( i = 0; i < 17; i++){
			num[i] = (int)c[i] - 48;
//			printf("%d",num[i]);	
		}
		sum = num[0]*7+num[1]*9+num[2]*10+num[3]*5+num[4]*8+num[5]*4+num[6]*2
				+num[7]*1+num[8]*6+num[9]*3+num[10]*7+num[11]*9+num[12]*10+num[13]*5
				+num[14]*8+num[15]*4+num[16]*2;
		sum %= 11;
		switch(sum){
			case 0:sum = 1;break;
			case 1:sum = 0;break;
			case 2:sum = 11;break;
			case 3:sum = 9;break;
			case 4:sum = 8;break;
			case 5:sum = 7;break;
			case 6:sum = 6;break;
			case 7:sum = 5;break;
			case 8:sum = 4;break;
			case 9:sum =3;break;
			case 10:sum = 2;break;
		}
		if(sum == 11){
			if(c[17] == 'X'){
				printf("right");
			}else{
				printf("wrong");
			}
			if(j!=n-1){
				printf("\n");
			}
		}else{
			int z = (int)c[17] - 48; 
			if( z == sum){
				printf("right");
			}else{
				printf("wrong");
			}
			if(j!=n-1){
				printf("\n");
			}
		} 
	} 
	 
}
