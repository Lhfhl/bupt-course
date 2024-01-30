/*     ��     */


/*���Ķ���˳��洢��ʾ*/

/*����˳��洢�ṹ����Ϊ*/
#define MAX_STRLEN  256
typedef  struct
{  
	char  str[MAX_STRLEN];
	int  length;
} StringType; 

/*�����������*/
Status  StrConcat(StringType s,StringType t)
/*  ����t���ᵽ��s֮�󣬽����Ȼ������s��  */
{  
   inti,j;
   if((s.length+t.length)>MAX_STRLEN)
    Return ERROR;                       /*  ����󳤶ȳ�����Χ  */
   for(i=0;i<t.length;i++)
    s.str[s.length+i]=t.str[i];         /*  ��t���ᵽ��s֮��  */
    s.length=s.length+t.length;         /* �޸������Ĵ����� */
   return OK;
}

/*���Ӵ�����*/
Status SubString (StringType s, int pos, int len, StringType *sub)
{  
  intk,j;
   if pos<1||pos>s.length||len<0||len>(s.length-pos+1))
	return ERROR;                   /*  �����Ƿ�  */
   sub->length=len-pos+1;          /*  ����Ӵ�����  */
   for(j=0, k=pos ; k<=leng ; k++, j++)
	sub->str[j]=s.str[i];           /*  ����ַ���������Ӵ�  */
   return OK;
} 

/*���Ķ�ʽ�洢�ṹ�����Ͷ���*/
typedef struct
{  
	char *ch;    /*  ���ǿգ������ȷ��䣬����ΪNULL */
	int length;      /*  ���ĳ���  */
} HString;

/*�����������*/
Status  Hstring  *StrConcat(HString  *T, HString *s1, HString *s2)
/*  ��T������s1��s2������ɵĴ�  */  
{   int k,  j , t_len ; 
if (T.ch)  free(T);     /*  �ͷžɿռ�   */
t_len=s1->length+s2->length ;
if ((p=(char *)malloc(sizeof((char)*t_len))==NULL)
{   printf(��ϵͳ�ռ䲻��������ռ�ʧ�� ��\n��) ; 
return ERROR  ;     }
for (j=0 ; j<s->length; j++) 
T->ch[j]=s1->ch[j] ;    /*  ����s���Ƶ���T�� */
for (k=s1->length, j=0 ; j<s2->length; k++, j++) 
T->ch[j]=s1->ch[j] ;    /*  ����s2���Ƶ���T�� */
free(s1->ch) ; 
free(s2->ch) ; 
return OK ;   
}

/*���Ŀ���ʽ�洢�����Ͷ���*/

/*��������Ͷ���*/
#define BLOCK_SIZE  4
typedef  struct  Blstrtype
{  char  data[BLOCK_SIZE] ;
struct  Blstrtype  *next;
}BNODE ;

/*�����������Ͷ���*/
typedef  struct
{ 
	BNODE  head;     /*  ͷָ��  */
    int  Strlen;        /*  ��ǰ����  */
} Blstring;

/*��ʽ�洢��ʾ*/
#define CHUNKSIZE 80       //�����û�����Ŀ��С
typedef struct Chunk{
   char  ch[CHUNKSIZE];
   struct Chunk *next;
}Chunk;

typedef struct{
   Chunk *head,*tail;      //����ͷָ���βָ��
   int curlen;             //���ĵ�ǰ����
}LString;

/*BF�㷨����*/
int  Index(Sstring S,Sstring T,int pos){
   i=pos;   j=1;
   while (i<=S[0] && j<=T[0]){
    if (S[i]=T[j]) 
	{
	++i; ++j;
	}
    else
	{ 
	i=i-j+2;  j=1;
	}
   if (j>T[0])   return i��T[0];
   else return 0;
}

/*KMP�㷨����*/
 

























 
