/*  ջ�Ͷ���  */

/*˳��ջ*/

/*˳��ջ�ı�ʾ*/
#define  MAXSIZE  100
typedef struct
{
		SElemType   *base;
		SElemType   *top;
		int stacksize;
}SqStack;

/*˳��ջ��ʼ��*/
Status InitStack( SqStack &S )
{
	S.base =new SElemType[MAXSIZE]��
	if( !S.base ) 	return OVERFLOW;
	S.top = S.base;
	S.stackSize = MAXSIZE;
	return OK;
}

/*�ж�˳��ջ�Ƿ�Ϊ��*/
bool StackEmpty( SqStack S )
{
	if(S.top == S.base) return true;
   else return false;
}

/*��˳��ջ�ĳ���*/
int StackLength( SqStack S )
{
	return S.top �C S.base;
}

/*���˳��ջ*/
Status ClearStack( SqStack S )
{
	if( S.base ) S.top = S.base;
	return OK;
}

/*���˳��ջ*/
Status ClearStack( SqStack S )
{
	if( S.base ) S.top = S.base;
	return OK;
}

/*����˳��ջ*/
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

/*˳��ջ��ջ*/
Status Push( SqStack &S, SElemType e)  
{
	if( S.top - S.base== S.stacksize ) // ջ��
        return ERROR; 	
	*S.top++=e;
	return OK;
}

/*˳��ջ��ջ*/
Status Pop( SqStack &S, SElemType &e)  
{
	if( S.top == S.base ) // ջ��
        return ERROR; 	
	e�� *--S.top;
	return OK;
}

/*ȡ˳��ջջ��Ԫ��*/
Status GetTop( SqStack S, SElemType &e)  
{
	if( S.top == S.base )	 return ERROR; 	// ջ��
	e = *( S.top �C 1 );
	return OK;
}

/*��ջ�ı�ʾ*/
typedef  struct StackNode {
      SElemType  data;
      struct StackNode *next;
 } StackNode,  *LinkStack;
LinkStack S;


/*  ��ջ  */ 

/*��ջ�ĳ�ʼ��*/
void InitStack(LinkStack &S )
{
	S=NULL;
}

/*�ж���ջ�Ƿ�Ϊ��*/
Status StackEmpty(LinkStack S)
{
	if (S==NULL) return TRUE;
	else return FALSE;
}

/*��ջ��ջ*/
Status Push(LinkStack &S , SElemType e)
{
	p=new StackNode;      //�����½��p      
    if (!p) exit(OVERFLOW);
    p->data=e; p->next=S; S=p;
	return OK; 
}

/*��ջ��ջ*/
Status Pop (LinkStack &S,SElemType &e)
{if (S==NULL) return ERROR;
 e = S-> data;  p = S;   S =  S-> next;
 delete p;   return OK;  
} 

/*ȡ��ջջ��Ԫ��*/
SElemType GetTop(LinkStack S)
{
    if (S==NULL) exit(1)��
	else return S�C>data;
}

/*  ����  */ 

/*���е�˳���ʾ������һά����base[M]*/
#define M  100   //�����г���
Typedef struct {
   QElemType *base;  //��ʼ���Ķ�̬����洢�ռ�
   int  front;            //ͷָ��   
   int  rear;             //βָ��
}SqQueue;

/*ѭ������*/

#define MAXQSIZE  100  //��󳤶�
Typedef struct {
   QElemType *base;  //��ʼ���Ķ�̬����洢�ռ�
   int  front;            //ͷָ��   
   int  rear;             //βָ��
}SqQueue;

/*ѭ�����г�ʼ��*/
Status InitQueue (SqQueue &Q){
    Q.base =new QElemType[MAXQSIZE] 
   if(!Q.base) exit(OVERFLOW);
    Q.front=Q.rear=0;
    return OK;
}

/*��ѭ�����еĳ���*/
int  QueueLength (SqQueue Q){
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;                             
 }
 
/*ѭ���������*/
Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear+1)%MAXQSIZE==Q.front)  return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}

/*ѭ�����г���*/
Status DeQueue (LinkQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.base[Q.front];
   Q.front=(Q.front+1)%MAXQSIZE;
   return OK;
}

/*������*/
typedef struct QNode{
   QElemType   data;
   struct Qnode  *next;
}Qnode, *QueuePtr;

typedef struct {
   QueuePtr  front;            //��ͷָ��   
   QueuePtr  rear;             //��βָ��
}LinkQueue; 

/*�����г�ʼ��*/
Status InitQueue (LinkQueue &Q){
   Q.front=Q.rear=(QueuePtr) malloc(sizeof(QNode)); 
    if(!Q.front) exit(OVERFLOW);
    Q.front->next=NULL;
     return OK;
}

/*����������*/
Status DestroyQueue (LinkQueue &Q){
   while(Q.front){
      Q.rear=Q.front->next;
      free(Q.front);
      Q.front=Q.rear;   }    
   return OK;
}

/*�ж��������Ƿ�Ϊ��*/
Status QueueEmpty (LinkQueue Q){
    return (Q.front==Q.rear);                             
 }

/*�������еĶ�ͷԪ��*/
Status GetHead (LinkQueue Q, QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   e=Q.front->next->data;
   return OK;
}

/*���������*/
Status EnQueue(LinkQueue &Q,QElemType e){
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data=e; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

/*�����г���*/
Status DeQueue (LinkQueue &Q,QElemType &e){
   if(Q.front==Q.rear) return ERROR;
   p=Q.front->next;
   e=p->data;
   Q.front->next=p->next;
   if(Q.rear==p) Q.rear=Q.front;
   delete p;
   return OK;
}









































































 
