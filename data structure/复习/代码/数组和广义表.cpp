/*数组和广义表*/

/*稀疏矩阵*/

/*三元组结点定义*/
#define MAX_SIZE 101
typedef int elemtype;
typedef struct
{   
	int  row;     /*行下标*/
	int  col;        /*列下标*/
	elemtype value;      /*元素值*/
}Triple;

/*三元组顺序表定义*/
typedef struct 
{   
	int  rn;         /*行数*/
	int  cn;         /*列数*/
	int  tn;         /*非0元素个数*/
	Triple  data[MAX_SIZE]; 
}TMatrix;

/*转置矩阵方法一的算法*/
void TransMatrix(TMatrix a , TMatrix b)
{   
	int p,q,col;
	b.rn=a.cn;b.cn=a.rn;b.tn=a.tn;   //置三元组表b.data的行、列数和非0元素个数
	if(b.tn==0)    
	{
	printf("The Matrix A=0\n");
	} 
	else
	{   
	q=0;
	for(col=1;col<=a.cn;col++)       /*每循环一次找到转置后的一个三元组*/
	for(p=0 ;p<a.tn;p++)       /*循环次数是非0元素个数*/
 	if(a.data[p].col==col)
        {
		b.data[q].row=a.data[p].col;
        b.data[q].col=a.data[p].row; 
        b.data[q].value=a.data[p].value; 
        q++;
		}
   }
}

/*快速转置算法*/
void  FastTransMatrix(TMatrix a, TMatrix b)
{    
	int p,q,col,k;
	int num[MAX_SIZE],copt[MAX_SIZE];
	b.rn=a.cn; 
	b.cn=a.rn; 
	b.tn=a.tn;/*   置三元组表b.data的行、列数和非0元素个数  */ 
	if(b.tn==0)    
	{
	printf("The Matrix A=0\n");
    }
	else
	{  
	for(col=1;col<=a.cn;++col)   
		num[col]=0;             /*  向量num[]初始化为0   */
    for(k=1;k<=a.tn;++k) 
    	++num[ a.data[k].col];              /*   求原矩阵中每一列非0元素个数  */
	for (cpot[0]=1,col=2;col<=a.cn;++col)
    	cpot[col]=cpot[col-1]+num[col-1];      /*  求第col列中第一个非0元在b.data中的序号 */
    for (p=1 ; p<=a.tn ; ++p)
    	{
		col=a.data[p].col;
		q=cpot[col];
		b.data[q].row=a.data[p].col;
    	b.data[q].col=a.data[p].row;
    	b.data[q].value=a.data[p].value; 
    	++cpot[col];      /*至关重要!!当本列中  */
    	}
	}
}

/*行逻辑链接的三元组顺序表*/
#define MAX_ROW 100
typedef struct  
{  
	Triple data[MAX_SIZE];     /*  非0元素的三元组表  */  
	int rpos[MAX_ROW];     /* 各行第一个非0位置表 */ 
	int rn,cn,tn;       /*  矩阵的行、列数和非0元个数  */
}RLSMatrix;

/*稀疏矩阵相乘的算法*/
void MultsMatrix(RLSMatrix a, RLSMatrix b, RLSMatrix c) /* 求矩阵A 、B的积C=A?B，采用行逻辑链接的顺序表 */
{   
	elemtype  ctemp[Max_Size];
	int  p,q,arow,ccol,brow,t; 
	if(a.cn!=b.rn)   
	{
	printf("Error\n"); 
	exit(0);  
	} 
	else         
	{    
	c.rn=a.rn;c.cn=b.n;c.tn=0;     /* 初始化C  */
	if(a.tn*b.tn!=0)        /* C  是非零矩阵  */

	{   for(arow=1;arow<=a.rn;++arow)
        {   
		ctemp[arow]=0;  /*  当前行累加器清零   */
        c.rpos[arow]=c.tn+1; p=a.rops[arow];
        for(;p<a.rpos[arow+1];++p)/* 对第arow行的每一个非0元素   */
            {
			brow=a.data[p].col;/*   找到元素在b.data[]中的行号  */
            if(brow<b.cn) t=(b.rpos[brow+1];
            else t=b.tn+1;   
                for (q=b.rpos[brow];q<t;++q)
                   { 
				    ccol=b.data[q].col; /*   积元素在c中的列号  */                     
					ctemp[ccol]+=a.data[p].value*b.data[q].value;
				   }
			}       /* 求出c中第arow行中的非0元素   */
                for (ccol=1 ; ccol<=c.cn ; ++ccol)
                if ( ctemp[ccol] !=0 )
		        {   
			    if ( ++c.tn>MAX_SIZE)
                	{   
		            printf("Error\n"); 
				    exit(0);   
				    } 
                else
                c.data[c.tn]=(arow,ccol,ctemp[ccol]);
                } 
        }  
	}	  
	}	
}


















 
