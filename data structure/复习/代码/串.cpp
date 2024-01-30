/*     串     */


/*串的定长顺序存储表示*/

/*定长顺序存储结构定义为*/
#define MAX_STRLEN  256
typedef  struct
{  
	char  str[MAX_STRLEN];
	int  length;
} StringType; 

/*串的联结操作*/
Status  StrConcat(StringType s,StringType t)
/*  将串t联结到串s之后，结果仍然保存在s中  */
{  
   inti,j;
   if((s.length+t.length)>MAX_STRLEN)
    Return ERROR;                       /*  联结后长度超出范围  */
   for(i=0;i<t.length;i++)
    s.str[s.length+i]=t.str[i];         /*  串t联结到串s之后  */
    s.length=s.length+t.length;         /* 修改联结后的串长度 */
   return OK;
}

/*求子串操作*/
Status SubString (StringType s, int pos, int len, StringType *sub)
{  
  intk,j;
   if pos<1||pos>s.length||len<0||len>(s.length-pos+1))
	return ERROR;                   /*  参数非法  */
   sub->length=len-pos+1;          /*  求得子串长度  */
   for(j=0, k=pos ; k<=leng ; k++, j++)
	sub->str[j]=s.str[i];           /*  逐个字符复制求得子串  */
   return OK;
} 

/*串的堆式存储结构的类型定义*/
typedef struct
{  
	char *ch;    /*  若非空，按长度分配，否则为NULL */
	int length;      /*  串的长度  */
} HString;

/*串的联结操作*/
Status  Hstring  *StrConcat(HString  *T, HString *s1, HString *s2)
/*  用T返回由s1和s2联结而成的串  */  
{   int k,  j , t_len ; 
if (T.ch)  free(T);     /*  释放旧空间   */
t_len=s1->length+s2->length ;
if ((p=(char *)malloc(sizeof((char)*t_len))==NULL)
{   printf(“系统空间不够，申请空间失败 ！\n”) ; 
return ERROR  ;     }
for (j=0 ; j<s->length; j++) 
T->ch[j]=s1->ch[j] ;    /*  将串s复制到串T中 */
for (k=s1->length, j=0 ; j<s2->length; k++, j++) 
T->ch[j]=s1->ch[j] ;    /*  将串s2复制到串T中 */
free(s1->ch) ; 
free(s2->ch) ; 
return OK ;   
}

/*串的块链式存储的类型定义*/

/*块结点的类型定义*/
#define BLOCK_SIZE  4
typedef  struct  Blstrtype
{  char  data[BLOCK_SIZE] ;
struct  Blstrtype  *next;
}BNODE ;

/*块链串的类型定义*/
typedef  struct
{ 
	BNODE  head;     /*  头指针  */
    int  Strlen;        /*  当前长度  */
} Blstring;

/*链式存储表示*/
#define CHUNKSIZE 80       //可由用户定义的块大小
typedef struct Chunk{
   char  ch[CHUNKSIZE];
   struct Chunk *next;
}Chunk;

typedef struct{
   Chunk *head,*tail;      //串的头指针和尾指针
   int curlen;             //串的当前长度
}LString;

/*BF算法描述*/
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
   if (j>T[0])   return i－T[0];
   else return 0;
}

/*KMP算法描述*/
 

























 
