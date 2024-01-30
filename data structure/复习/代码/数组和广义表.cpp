/*����͹����*/

/*ϡ�����*/

/*��Ԫ���㶨��*/
#define MAX_SIZE 101
typedef int elemtype;
typedef struct
{   
	int  row;     /*���±�*/
	int  col;        /*���±�*/
	elemtype value;      /*Ԫ��ֵ*/
}Triple;

/*��Ԫ��˳�����*/
typedef struct 
{   
	int  rn;         /*����*/
	int  cn;         /*����*/
	int  tn;         /*��0Ԫ�ظ���*/
	Triple  data[MAX_SIZE]; 
}TMatrix;

/*ת�þ��󷽷�һ���㷨*/
void TransMatrix(TMatrix a , TMatrix b)
{   
	int p,q,col;
	b.rn=a.cn;b.cn=a.rn;b.tn=a.tn;   //����Ԫ���b.data���С������ͷ�0Ԫ�ظ���
	if(b.tn==0)    
	{
	printf("The Matrix A=0\n");
	} 
	else
	{   
	q=0;
	for(col=1;col<=a.cn;col++)       /*ÿѭ��һ���ҵ�ת�ú��һ����Ԫ��*/
	for(p=0 ;p<a.tn;p++)       /*ѭ�������Ƿ�0Ԫ�ظ���*/
 	if(a.data[p].col==col)
        {
		b.data[q].row=a.data[p].col;
        b.data[q].col=a.data[p].row; 
        b.data[q].value=a.data[p].value; 
        q++;
		}
   }
}

/*����ת���㷨*/
void  FastTransMatrix(TMatrix a, TMatrix b)
{    
	int p,q,col,k;
	int num[MAX_SIZE],copt[MAX_SIZE];
	b.rn=a.cn; 
	b.cn=a.rn; 
	b.tn=a.tn;/*   ����Ԫ���b.data���С������ͷ�0Ԫ�ظ���  */ 
	if(b.tn==0)    
	{
	printf("The Matrix A=0\n");
    }
	else
	{  
	for(col=1;col<=a.cn;++col)   
		num[col]=0;             /*  ����num[]��ʼ��Ϊ0   */
    for(k=1;k<=a.tn;++k) 
    	++num[ a.data[k].col];              /*   ��ԭ������ÿһ�з�0Ԫ�ظ���  */
	for (cpot[0]=1,col=2;col<=a.cn;++col)
    	cpot[col]=cpot[col-1]+num[col-1];      /*  ���col���е�һ����0Ԫ��b.data�е���� */
    for (p=1 ; p<=a.tn ; ++p)
    	{
		col=a.data[p].col;
		q=cpot[col];
		b.data[q].row=a.data[p].col;
    	b.data[q].col=a.data[p].row;
    	b.data[q].value=a.data[p].value; 
    	++cpot[col];      /*������Ҫ!!��������  */
    	}
	}
}

/*���߼����ӵ���Ԫ��˳���*/
#define MAX_ROW 100
typedef struct  
{  
	Triple data[MAX_SIZE];     /*  ��0Ԫ�ص���Ԫ���  */  
	int rpos[MAX_ROW];     /* ���е�һ����0λ�ñ� */ 
	int rn,cn,tn;       /*  ������С������ͷ�0Ԫ����  */
}RLSMatrix;

/*ϡ�������˵��㷨*/
void MultsMatrix(RLSMatrix a, RLSMatrix b, RLSMatrix c) /* �����A ��B�Ļ�C=A?B���������߼����ӵ�˳��� */
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
	c.rn=a.rn;c.cn=b.n;c.tn=0;     /* ��ʼ��C  */
	if(a.tn*b.tn!=0)        /* C  �Ƿ������  */

	{   for(arow=1;arow<=a.rn;++arow)
        {   
		ctemp[arow]=0;  /*  ��ǰ���ۼ�������   */
        c.rpos[arow]=c.tn+1; p=a.rops[arow];
        for(;p<a.rpos[arow+1];++p)/* �Ե�arow�е�ÿһ����0Ԫ��   */
            {
			brow=a.data[p].col;/*   �ҵ�Ԫ����b.data[]�е��к�  */
            if(brow<b.cn) t=(b.rpos[brow+1];
            else t=b.tn+1;   
                for (q=b.rpos[brow];q<t;++q)
                   { 
				    ccol=b.data[q].col; /*   ��Ԫ����c�е��к�  */                     
					ctemp[ccol]+=a.data[p].value*b.data[q].value;
				   }
			}       /* ���c�е�arow���еķ�0Ԫ��   */
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


















 
