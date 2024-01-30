#include<stdio.h>

//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int elementCount) ;

//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc) ; 

//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;
    
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    selectSort(num,n) ; 
    return 0 ;
}

/* 请在这里填写答案 */

//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int elementCount){
	int i; 
	for( i = 0; i < elementCount - 1; i++){
		int loc = findMin(data,i,elementCount-1);
		int m = data[i];
		data[i] = data[loc];
		data[loc] = m;
		outputData(data,elementCount);
	}
} 

//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc){
	int minLoc = startLoc;
	int min = data[startLoc];
	int i;
	for( i = startLoc+1; i <= endLoc; i++){
		if(min > data[i]){
			min = data[i];
			minLoc = i;
		} 
	}
	return minLoc; 
} 

//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int elementCount){
	int i;
	for( i = 0; i < elementCount; i++){
		if( i != elementCount-1 ){
			printf("%d ",data[i]);
		}else{
			printf("%d\n",data[i]);
		}
	}
} 

