#include<stdio.h>

//ѡ���������� 
//����˵�������飬����������Ԫ�ظ��� 
void selectSort(int data[],int elementCount) ;

//�������ܣ��������е���СֵԪ�أ����������±� 
//����˵������������������ʼλ���±꣬������ֹλ���±�
int findMin(int data[], int startLoc, int endLoc) ; 

//�������������Ԫ�� 
//����˵�������飬����������Ԫ�ظ��� 
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

/* ����������д�� */

//ѡ���������� 
//����˵�������飬����������Ԫ�ظ��� 
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

//�������ܣ��������е���СֵԪ�أ����������±� 
//����˵������������������ʼλ���±꣬������ֹλ���±�
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

//�������������Ԫ�� 
//����˵�������飬����������Ԫ�ظ��� 
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

