/*顺序表*/ 

/*顺序表的类型定义*/
#define  MAXSIZE 100     //最大长度
typedef  struct {
  ElemType  *elem;     //指向数据元素的基地址
  int  length;          //线性表的当前长度                                                      
 }SqList;
 
 /*eg:图书表的顺序存储结构类型定义*/
 #define MAXSIZE 10000	//图书表可能达到的最大长度 
typedef struct			//图书信息定义
{ 
   char no[20];			//图书ISBN
   char name[50];		//图书名字
   float price; 			//图书价格
}Book; 
typedef struct
{ 
   Book *elem;	//存储空间的基地址 
   int length;		//图书表中当前图书个数 
}SqList;		//图书表的顺序存储结构类型为SqList
/*malloc(m)：开辟m字节长度的地址空间，并返回这段空间的首地址

  sizeof(x)：计算变量x的长度

  free(p)：释放指针p所指变量的存储空间，即彻底删除一个变量*/

/*线性表的重要基本操作*/
/*
1.  初始化
2.  取值
3.  查找
4.  插入
5.  删除
*/
/*初始化线性表L （参数用引用）*/
Status InitList_Sq(SqList &L){    //构造一个空的顺序表L
    L.elem=new ElemType[MAXSIZE];   //为顺序表分配空间
    if(!L.elem) exit(OVERFLOW);       //存储分配失败
    L.length=0;					  //空表长度为0
    return OK;
}
/*初始化线性表L （参数用指针）*/
Status InitList_Sq(SqList *L){    //构造一个空的顺序表L
    L-> elem=new ElemType[MAXSIZE];   //为顺序表分配空间
    if(! L-> elem) exit(OVERFLOW);       //存储分配失败
    L-> length=0;	            	  //空表长度为0
    return OK;
}
/*销毁线性表L*/
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //释放存储空间
}
/*清空线性表L*/
void ClearList(SqList &L) 
{
   L.length=0;                //将线性表的长度置为0
}
/*求线性表L的长度*/
int GetLength(SqList L)
{
   return (L.length);             
}
/*判断线性表L是否为空*/ 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}

/*取值*/ 
/*获取线性表L中的某个数据元素的内容*/
int GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;   //判断i值是否合理，若不合理，返回ERROR
  e=L.elem[i-1];   //第i-1的单元存储着第i个数据
  return OK;
}


/*查找*/
/*在线性表L中查找值为e的数据元素*/ 
int LocateELem(SqList L,ElemType e)
{
  for (i=0;i< L.length;i++)
      if (L.elem[i]==e) return i+1;                
  return 0;
}


/*插入*/ 
/*在线性表L中第i个数据元素之前插入数据元素e,AMN=n/2*/
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;	         //i值不合法
   if(L.length==MAXSIZE) return ERROR;    //当前存储空间已满     
   for(j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
    L.elem[i-1]=e;                     //将新元素e放入第i个位置
  ++L.length;		     	//表长增1
  return OK;
}


/*删除*/
/*将线性表L中第i个数据元素删除,AMN=(n-1)/2*/
Status ListDelete_Sq(SqList &L,int i){
   if((i<1)||(i>L.length)) return ERROR;	 //i值不合法
   for (j=i;j<=L.length-1;j++)                   
　  　L.elem[j-1]=L.elem[j];       //被删除元素之后的元素前移  
   --L.length;               	      //表长减1
  return OK;
} 

//查找、插入、删除算法的平均时间复杂度为O(n);顺序表的空间复杂度S(n)=O(1)（没有占用辅助空间）


/*链表*/

/*单链表*/
/*单链表的存储结构定义*/
typedef struct LNode{
     ElemType   data;       //数据域
     struct LNode  *next;   //指针域
}LNode,*LinkList;   // *LinkList为Lnode类型的指针 ,LNode *p == LinkList p

/*单链表基本操作的实现*/
/*
1.  初始化
2.  取值
3.  查找
4.  插入
5.  删除
*/

/*初始化(构造一个空表 )*/
Status InitList_L(LinkList &L){ 
   L=new LNode;                    	
   L->next=NULL;　　　　　
   return OK; 
} //【算法步骤】（1）生成新结点作头结点，用头指针L指向头结点。（2）头结点的指针域置空。

/*销毁*/
Status DestroyList_L(LinkList &L){
    LinkList p;
       while(L)//while循环 
        {
            p=L;  
            L=L->next;
            delete p;  
        }
     return OK;
 }

/*清空*/ 
Status ClearList(LinkList & L){  // 将L重置为空表 
   LinkList p,q;
   p=L->next;   //p指向第一个结点
   while(p)       //没到表尾 
      {  q=p->next; delete p;     p=q;   }
   L->next=NULL;   //头结点指针域为空 
   return OK;
 }

/*求表长*/
int  ListLength_L(LinkList L){  //返回L中数据元素个数
    LinkList p;
    p=L->next;  //p指向第一个结点
     i=0;             
     while(p){  //遍历单链表,统计结点数
           i++;
           p=p->next;    } 
    return i;                             
 }

/*判断表是否为空*/
int ListEmpty(LinkList L){   //若L为空表，则返回1，否则返回0 
   if(L->next)      //非空 
     return 0;
   else
     return 1;
 }

/*取值*/
/*获取线性表L中的某个数据元素的内容*/
Status GetElem_L(LinkList L,int i,ElemType &e){ 
    p=L->next;j=1; //初始化
     while(p&&j<i){	//向后扫描，直到p指向第i个元素或p为空 
       p=p->next; ++j; 
     } 
     if(!p || j>i)return ERROR; //第i个元素不存在 
     e=p->data; //取第i个元素 
     return OK; 
}//GetElem_L 

/*查找*/
/*在线性表L中查找值为e的数据元素*/
LNode *LocateELem_L (LinkList L，Elemtype e) { //返回L中值为e的数据元素的地址，查找失败返回NULL
  p=L->next;
  while(p &&p->data!=e)  
        p=p->next;                		
  return p; 	
} 
//在线性表L中查找值为e的数据元素
int LocateELem_L (LinkList L，Elemtype e) {
 //返回L中值为e的数据元素的位置序号，查找失败返回0 
  p=L->next; j=1;
  while(p &&p->data!=e)  
        {p=p->next;  j++;}          		
  if(p) return j; 
  else return 0;
} 

/*插入*/ 
/*在L中第i个元素之前插入数据元素e */
Status ListInsert_L(LinkList &L,int i,ElemType e){ 
     p=L;j=0; 
      while(p&&j<i?1){p=p->next;++j;}	//寻找第i?1个结点 
      if(!p||j>i?1)return ERROR;	//i大于表长?+?1或者小于1  
      s=new LNode;			//生成新结点s 
      s->data=e;      		           //将结点s的数据域置为e 
      s->next=p->next;	   	          //将结点s插入L中 
      p->next=s; 
      return OK; 
}//ListInsert_L 

/*删除*/
//将线性表L中第i个数据元素删除
 Status ListDelete_L(LinkList &L,int i,ElemType &e){
    p=L;j=0; 
    while(p->next &&j<i-1){//寻找第i个结点，并令p指向其前驱 
        p=p->next; ++j; 
    } 
    if(!(p->next)||j>i-1) return ERROR; //删除位置不合理 
    q=p->next; //临时保存被删结点的地址以备释放 
    p->next=q->next; 	//改变删除结点前驱结点的指针域 
    e=q->data; 	//保存删除结点的数据域 
    delete q; 	//释放删除结点的空间 
 return OK; 
}//ListDelete_L

/*单链表的建立（前插法）*/
void CreateList_F(LinkList &L,int n){ 
     L=new LNode; 
      L->next=NULL; //先建立一个带头结点的单链表 
      for(i=n;i>0;--i){ 
        p=new LNode; //生成新结点 
        scantf(“%d%, p->data); //输入元素值 
        p->next=L->next;L->next=p; 	//插入到表头 
     } 
}//CreateList_F 
/*单链表的建立（尾插法）*/
void CreateList_L(LinkList &L,int n){ //正位序输入n个元素的值，建立带表头结点的单链表L 
      L=new LNode; 
      L->next=NULL; 	
      r=L; 	//尾指针r指向头结点 
      for(i=0;i<n;++i){ 
        p=new LNode;	　	//生成新结点 
        scanf(“%d”,&p->data);   		//输入元素值 
        p->next=NULL; r->next=p; 	    	//插入到表尾 
        r=p; 	//r指向新的尾结点 
      } 
}//CreateList_L  


/*循环链表的合并*/
LinkList Connect(LinkList Ta,LinkList Tb)
{//假设Ta、Tb都是非空的单循环链表
	p=Ta->next;               //p存表头结点
    Ta->next=Tb->next->next;  //Tb表头连结Ta表尾
    deleteTb->next;           //释放Tb表头结点
    Tb->next=p;               //修改指针
    return  Tb;
}

/*双向链表*/
typedef struct DuLNode{
    ElemType   data;              
    struct DuLNode  *prior;  
    struct DuLNode  *next;  
}DuLNode, *DuLinkList

/*双向链表的插入*/
Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){
   if(!(p=GetElemP_DuL(L,i))) return ERROR;
    s=new DuLNode; 
   s->data=e;
   s->prior=p->prior;  
   p->prior->next=s;
   s->next=p;  
   p->prior=s;
   return OK;
}

/*双向链表的删除*/
Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
   if(!(p=GetElemP_DuL(L,i)))     return ERROR;
   e=p->data;
   p->prior->next=p->next;
   p->next->prior=p->prior;
   delete p; 
   return OK;
}

/*线性表的合并*/
/*假设利用两个线性表La和Lb分别表示两个集合A和B,现要求一个新的集合为A与B的并集*/ 
void union(List &La, List Lb){
  La_len=ListLength(La);
  Lb_len=ListLength(Lb); 
  for(i=1;i<=Lb_len;i++){
      GetElem(Lb,i,e);
      if(!LocateElem(La,e)) 
           ListInsert(&La,++La_len,e);                        
  }
}

/*有序的顺序表合并*/
void MergeList_Sq(SqList LA,SqList LB,SqList &LC){ 
     pa=LA.elem;  pb=LB.elem; 	//指针pa和pb的初值分别指向两个表的第一个元素 
     LC.length=LA.length+LB.length;      	//新表长度为待合并两表的长度之和 
     LC.elem=new ElemType[LC.length];    	//为合并后的新表分配一个数组空间 
     pc=LC.elem;                         		//指针pc指向新表的第一个元素 
     pa_last=LA.elem+LA.length-1; 	//指针pa_last指向LA表的最后一个元素 
     pb_last=LB.elem+LB.length-1; 	//指针pb_last指向LB表的最后一个元素 
     while(pa<=pa_last && pb<=pb_last){  	//两个表都非空 
      if(*pa<=*pb) *pc++=*pa++;        		//依次“摘取”两表中值较小的结点       else *pc++=*pb++;      } 
     while(pa<=pa_last)  *pc++=*pa++;             //LB表已到达表尾
     while(pb<=pb_last)  *pc++=*pb++;          //LA表已到达表尾 
}//MergeList_Sq 

/*        有序链表合并        */
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //用La的头结点作为Lc的头结点 
   while(pa && pb){
      if(pa->data<=pb->data){ pc->next=pa;pc=pa;pa=pa->next;}
      else{pc->next=pb; pc=pb; pb=pb->next;}
   pc->next=pa?pa:pb;    //插入剩余段  
   delete Lb;}             //释放Lb的头结点
}

/*     有序的链表合并(结果无重复元素)     */
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //用La的头结点作为Lc的头结点 
   while(pa && pb){
   if (pa->data == pb->data)
        { pbd=pb; pb = pb->next; delete pbd;}
     else if (pa->data<pb->data)
                 { pc->next=pa;pc=pa;pa=pa->next;}
              else  {pc->next=pb; pc=pb; pb=pb->next;};
   pc->next=pa?pa:pb;    //插入剩余段  
   delete Lb;}             //释放Lb的头结点 
}













