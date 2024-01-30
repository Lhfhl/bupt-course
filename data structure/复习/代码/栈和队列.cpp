/*  栈和队列  */

/*顺序栈*/

/*顺序栈的表示*/
#define  MAXSIZE  100
typedef struct
{
		SElemType   *base;
		SElemType   *top;
		int stacksize;
}SqStack;

/*顺序栈初始化*/
Status InitStack( SqStack &S )
{
	S.base =new SElemType[MAXSIZE]；
	if( !S.base ) 	return OVERFLOW;
	S.top = S.base;
	S.stackSize = MAXSIZE;
	return OK;
}

/*判断顺序栈是否为空*/
bool StackEmpty( SqStack S )
{
	if(S.top == S.base) return true;
   else return false;
}

/*求顺序栈的长度*/
int StackLength( SqStack S )
{
	return S.top – S.base;
}

/*清空顺序栈*/
Status ClearStack( SqStack S )
{
	if( S.base ) S.top = S.base;
	return OK;
}

/*清空顺序栈*/
Status ClearStack( SqStack S )
{
	if( S.base ) S.top = S.base;
	return OK;
}

/*销毁顺序栈*/
Status DestroyStack( SqStack &S )
{
	if( S.base )
	{
		delete S.base ;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
  return OK;
}

/*顺序栈进栈*/
Status Push( SqStack &S, SElemType e)  
{
	if( S.top - S.base== S.stacksize ) // 栈满
        return ERROR; 	
	*S.top++=e;
	return OK;
}

/*顺序栈出栈*/
Status Pop( SqStack &S, SElemType &e)  
{
	if( S.top == S.base ) // 栈空
        return ERROR; 	
	e＝ *--S.top;
	return OK;
}

/*取顺序栈栈顶元素*/
Status GetTop( SqStack S, SElemType &e)  
{
	if( S.top == S.base )	 return ERROR; 	// 栈空
	e = *( S.top – 1 );
	return OK;
}

/*链栈的表示*/
typedef  struct StackNode {
      SElemType  data;
      struct StackNode *next;
 } StackNode,  *LinkStack;
LinkStack S;


/*  链栈  */ 

/*链栈的初始化*/
void InitStack(LinkStack &S )
{
	S=NULL;
}

/*判断链栈是否为空*/
Status StackEmpty(LinkStack S)
{
	if (S==NULL) return TRUE;
	else return FALSE;
}

/*链栈进栈*/
Status Push(LinkStack &S , SElemType e)
{
	p=new StackNode;      //生成新结点p      
    if (!p) exit(OVERFLOW);
    p->data=e; p->next=S; S=p;
	return OK; 
}

/*链栈出栈*/
Status Pop (LinkStack &S,SElemType &e)
{if (S==NULL) return ERROR;
 e = S-> data;  p = S;   S =  S-> next;
 delete p;   return OK;  
} 

/*取链栈栈顶元素*/
SElemType GetTop(LinkStack S)
{
    if (S==NULL) exit(1)；
	else return S–>data;
}

/*  队列  */ 

/*队列的顺序表示－－用一维数组base[M]*/
#define M  100   //最大队列长度
Typedef struct {
   QElemType *base;  //初始化的动态分配存储空间
   int  front;            //头指针   
   int  rear;             //尾指针
}SqQueue;

/*循环队列*/

#define MAXQSIZE  100  //最大长度
Typedef struct {
   QElemType *base;  //初始化的动态分配存储空间
   int  front;            //头指针   
   int  rear;             //尾指针
}SqQueue;

/*循环队列初始化*/
Status InitQueue (SqQueue &Q){
    Q.base =new QElemType[MAXQSIZE] 
   if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}

/*求循环队列的长度*/
int  QueueLength (SqQueue Q){
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;                             
 }
 
/*循环队列入队*/
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}

/*循环队列出队*/
Status DeQueue (LinkQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
}

/*链队列*/
typedef struct QNode{
   QElemType   data;
   struct Qnode  *next;
}Qnode, *QueuePtr;

typedef struct {
   QueuePtr  front;            //队头指针   
   QueuePtr  rear;             //队尾指针
}LinkQueue; 

/*链队列初始化*/
Status InitQueue (LinkQueue &Q){
   Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode)); 
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
     return OK;
}

/*销毁链队列*/
Status DestroyQueue (LinkQueue &Q){
   while(Q.front){
      Q.rear=Q.front->next;
      free(Q.front);
      Q.front=Q.rear;   }    
   return OK;
}

/*判断链队列是否为空*/
Status QueueEmpty (LinkQueue Q){
    return (Q.front==Q.rear);                             
 }

/*求链队列的队头元素*/
Status GetHead (LinkQueue Q, QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.front->next->data;
   return OK;
}

/*链队列入队*/
Status EnQueue(LinkQueue &Q,QElemType e){
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data=e; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

/*链队列出队*/
Status DeQueue (LinkQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p) Q.rear=Q.front;
   delete p;
   return OK;
}









































































 
