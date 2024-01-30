/*˳���*/ 

/*˳�������Ͷ���*/
#define  MAXSIZE 100     //��󳤶�
typedef  struct {
  ElemType  *elem;     //ָ������Ԫ�صĻ���ַ
  int  length;          //���Ա�ĵ�ǰ����                                                      
 }SqList;
 
 /*eg:ͼ����˳��洢�ṹ���Ͷ���*/
 #define MAXSIZE 10000	//ͼ�����ܴﵽ����󳤶� 
typedef struct			//ͼ����Ϣ����
{ 
   char no[20];			//ͼ��ISBN
   char name[50];		//ͼ������
   float price; 			//ͼ��۸�
}Book; 
typedef struct
{ 
   Book *elem;	//�洢�ռ�Ļ���ַ 
   int length;		//ͼ����е�ǰͼ����� 
}SqList;		//ͼ����˳��洢�ṹ����ΪSqList
/*malloc(m)������m�ֽڳ��ȵĵ�ַ�ռ䣬��������οռ���׵�ַ

  sizeof(x)���������x�ĳ���

  free(p)���ͷ�ָ��p��ָ�����Ĵ洢�ռ䣬������ɾ��һ������*/

/*���Ա����Ҫ��������*/
/*
1.  ��ʼ��
2.  ȡֵ
3.  ����
4.  ����
5.  ɾ��
*/
/*��ʼ�����Ա�L �����������ã�*/
Status InitList_Sq(SqList &L){    //����һ���յ�˳���L
    L.elem=new ElemType[MAXSIZE];   //Ϊ˳������ռ�
    if(!L.elem) exit(OVERFLOW);       //�洢����ʧ��
    L.length=0;					  //�ձ���Ϊ0
    return OK;
}
/*��ʼ�����Ա�L ��������ָ�룩*/
Status InitList_Sq(SqList *L){    //����һ���յ�˳���L
    L-> elem=new ElemType[MAXSIZE];   //Ϊ˳������ռ�
    if(! L-> elem) exit(OVERFLOW);       //�洢����ʧ��
    L-> length=0;	            	  //�ձ���Ϊ0
    return OK;
}
/*�������Ա�L*/
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;    //�ͷŴ洢�ռ�
}
/*������Ա�L*/
void ClearList(SqList &L) 
{
   L.length=0;                //�����Ա�ĳ�����Ϊ0
}
/*�����Ա�L�ĳ���*/
int GetLength(SqList L)
{
   return (L.length);             
}
/*�ж����Ա�L�Ƿ�Ϊ��*/ 
int IsEmpty(SqList L)
{
  if (L.length==0) return 1;      
   else return 0;
}

/*ȡֵ*/ 
/*��ȡ���Ա�L�е�ĳ������Ԫ�ص�����*/
int GetElem(SqList L,int i,ElemType &e)
{
  if (i<1||i>L.length) return ERROR;   //�ж�iֵ�Ƿ����������������ERROR
  e=L.elem[i-1];   //��i-1�ĵ�Ԫ�洢�ŵ�i������
  return OK;
}


/*����*/
/*�����Ա�L�в���ֵΪe������Ԫ��*/ 
int LocateELem(SqList L,ElemType e)
{
  for (i=0;i< L.length;i++)
      if (L.elem[i]==e) return i+1;                
  return 0;
}


/*����*/ 
/*�����Ա�L�е�i������Ԫ��֮ǰ��������Ԫ��e,AMN=n/2*/
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
   if(i<1 || i>L.length+1) return ERROR;	         //iֵ���Ϸ�
   if(L.length==MAXSIZE) return ERROR;    //��ǰ�洢�ռ�����     
   for(j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
    L.elem[i-1]=e;                     //����Ԫ��e�����i��λ��
  ++L.length;		     	//����1
  return OK;
}


/*ɾ��*/
/*�����Ա�L�е�i������Ԫ��ɾ��,AMN=(n-1)/2*/
Status ListDelete_Sq(SqList &L,int i){
   if((i<1)||(i>L.length)) return ERROR;	 //iֵ���Ϸ�
   for (j=i;j<=L.length-1;j++)                   
��  ��L.elem[j-1]=L.elem[j];       //��ɾ��Ԫ��֮���Ԫ��ǰ��  
   --L.length;               	      //����1
  return OK;
} 

//���ҡ����롢ɾ���㷨��ƽ��ʱ�临�Ӷ�ΪO(n);˳���Ŀռ临�Ӷ�S(n)=O(1)��û��ռ�ø����ռ䣩


/*����*/

/*������*/
/*������Ĵ洢�ṹ����*/
typedef struct LNode{
     ElemType   data;       //������
     struct LNode  *next;   //ָ����
}LNode,*LinkList;   // *LinkListΪLnode���͵�ָ�� ,LNode *p == LinkList p

/*���������������ʵ��*/
/*
1.  ��ʼ��
2.  ȡֵ
3.  ����
4.  ����
5.  ɾ��
*/

/*��ʼ��(����һ���ձ� )*/
Status InitList_L(LinkList &L){ 
   L=new LNode;                    	
   L->next=NULL;����������
   return OK; 
} //���㷨���衿��1�������½����ͷ��㣬��ͷָ��Lָ��ͷ��㡣��2��ͷ����ָ�����ÿա�

/*����*/
Status DestroyList_L(LinkList &L){
    LinkList p;
       while(L)//whileѭ�� 
        {
            p=L;  
            L=L->next;
            delete p;  
        }
     return OK;
 }

/*���*/ 
Status ClearList(LinkList & L){  // ��L����Ϊ�ձ� 
   LinkList p,q;
   p=L->next;   //pָ���һ�����
   while(p)       //û����β 
      {  q=p->next; delete p;     p=q;   }
   L->next=NULL;   //ͷ���ָ����Ϊ�� 
   return OK;
 }

/*���*/
int  ListLength_L(LinkList L){  //����L������Ԫ�ظ���
    LinkList p;
    p=L->next;  //pָ���һ�����
     i=0;             
     while(p){  //����������,ͳ�ƽ����
           i++;
           p=p->next;    } 
    return i;                             
 }

/*�жϱ��Ƿ�Ϊ��*/
int ListEmpty(LinkList L){   //��LΪ�ձ��򷵻�1�����򷵻�0 
   if(L->next)      //�ǿ� 
     return 0;
   else
     return 1;
 }

/*ȡֵ*/
/*��ȡ���Ա�L�е�ĳ������Ԫ�ص�����*/
Status GetElem_L(LinkList L,int i,ElemType &e){ 
    p=L->next;j=1; //��ʼ��
     while(p&&j<i){	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ�� 
       p=p->next; ++j; 
     } 
     if(!p || j>i)return ERROR; //��i��Ԫ�ز����� 
     e=p->data; //ȡ��i��Ԫ�� 
     return OK; 
}//GetElem_L 

/*����*/
/*�����Ա�L�в���ֵΪe������Ԫ��*/
LNode *LocateELem_L (LinkList L��Elemtype e) { //����L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
  p=L->next;
  while(p &&p->data!=e)  
        p=p->next;                		
  return p; 	
} 
//�����Ա�L�в���ֵΪe������Ԫ��
int LocateELem_L (LinkList L��Elemtype e) {
 //����L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0 
  p=L->next; j=1;
  while(p &&p->data!=e)  
        {p=p->next;  j++;}          		
  if(p) return j; 
  else return 0;
} 

/*����*/ 
/*��L�е�i��Ԫ��֮ǰ��������Ԫ��e */
Status ListInsert_L(LinkList &L,int i,ElemType e){ 
     p=L;j=0; 
      while(p&&j<i?1){p=p->next;++j;}	//Ѱ�ҵ�i?1����� 
      if(!p||j>i?1)return ERROR;	//i���ڱ�?+?1����С��1  
      s=new LNode;			//�����½��s 
      s->data=e;      		           //�����s����������Ϊe 
      s->next=p->next;	   	          //�����s����L�� 
      p->next=s; 
      return OK; 
}//ListInsert_L 

/*ɾ��*/
//�����Ա�L�е�i������Ԫ��ɾ��
 Status ListDelete_L(LinkList &L,int i,ElemType &e){
    p=L;j=0; 
    while(p->next &&j<i-1){//Ѱ�ҵ�i����㣬����pָ����ǰ�� 
        p=p->next; ++j; 
    } 
    if(!(p->next)||j>i-1) return ERROR; //ɾ��λ�ò����� 
    q=p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� 
    p->next=q->next; 	//�ı�ɾ�����ǰ������ָ���� 
    e=q->data; 	//����ɾ������������ 
    delete q; 	//�ͷ�ɾ�����Ŀռ� 
 return OK; 
}//ListDelete_L

/*������Ľ�����ǰ�巨��*/
void CreateList_F(LinkList &L,int n){ 
     L=new LNode; 
      L->next=NULL; //�Ƚ���һ����ͷ���ĵ����� 
      for(i=n;i>0;--i){ 
        p=new LNode; //�����½�� 
        scantf(��%d%, p->data); //����Ԫ��ֵ 
        p->next=L->next;L->next=p; 	//���뵽��ͷ 
     } 
}//CreateList_F 
/*������Ľ�����β�巨��*/
void CreateList_L(LinkList &L,int n){ //��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
      L=new LNode; 
      L->next=NULL; 	
      r=L; 	//βָ��rָ��ͷ��� 
      for(i=0;i<n;++i){ 
        p=new LNode;	��	//�����½�� 
        scanf(��%d��,&p->data);   		//����Ԫ��ֵ 
        p->next=NULL; r->next=p; 	    	//���뵽��β 
        r=p; 	//rָ���µ�β��� 
      } 
}//CreateList_L  


/*ѭ������ĺϲ�*/
LinkList Connect(LinkList Ta,LinkList Tb)
{//����Ta��Tb���Ƿǿյĵ�ѭ������
	p=Ta->next;               //p���ͷ���
    Ta->next=Tb->next->next;  //Tb��ͷ����Ta��β
    deleteTb->next;           //�ͷ�Tb��ͷ���
    Tb->next=p;               //�޸�ָ��
    return  Tb;
}

/*˫������*/
typedef struct DuLNode{
    ElemType   data;              
    struct DuLNode  *prior;  
    struct DuLNode  *next;  
}DuLNode, *DuLinkList

/*˫������Ĳ���*/
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

/*˫�������ɾ��*/
Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){
   if(!(p=GetElemP_DuL(L,i)))     return ERROR;
   e=p->data;
   p->prior->next=p->next;
   p->next->prior=p->prior;
   delete p; 
   return OK;
}

/*���Ա�ĺϲ�*/
/*���������������Ա�La��Lb�ֱ��ʾ��������A��B,��Ҫ��һ���µļ���ΪA��B�Ĳ���*/ 
void union(List &La, List Lb){
  La_len=ListLength(La);
  Lb_len=ListLength(Lb); 
  for(i=1;i<=Lb_len;i++){
      GetElem(Lb,i,e);
      if(!LocateElem(La,e)) 
           ListInsert(&La,++La_len,e);                        
  }
}

/*�����˳���ϲ�*/
void MergeList_Sq(SqList LA,SqList LB,SqList &LC){ 
     pa=LA.elem;  pb=LB.elem; 	//ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ�� 
     LC.length=LA.length+LB.length;      	//�±���Ϊ���ϲ�����ĳ���֮�� 
     LC.elem=new ElemType[LC.length];    	//Ϊ�ϲ�����±����һ������ռ� 
     pc=LC.elem;                         		//ָ��pcָ���±�ĵ�һ��Ԫ�� 
     pa_last=LA.elem+LA.length-1; 	//ָ��pa_lastָ��LA������һ��Ԫ�� 
     pb_last=LB.elem+LB.length-1; 	//ָ��pb_lastָ��LB������һ��Ԫ�� 
     while(pa<=pa_last && pb<=pb_last){  	//�������ǿ� 
      if(*pa<=*pb) *pc++=*pa++;        		//���Ρ�ժȡ��������ֵ��С�Ľ��       else *pc++=*pb++;      } 
     while(pa<=pa_last)  *pc++=*pa++;             //LB���ѵ����β
     while(pb<=pb_last)  *pc++=*pb++;          //LA���ѵ����β 
}//MergeList_Sq 

/*        ��������ϲ�        */
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //��La��ͷ�����ΪLc��ͷ��� 
   while(pa && pb){
      if(pa->data<=pb->data){ pc->next=pa;pc=pa;pa=pa->next;}
      else{pc->next=pb; pc=pb; pb=pb->next;}
   pc->next=pa?pa:pb;    //����ʣ���  
   delete Lb;}             //�ͷ�Lb��ͷ���
}

/*     ���������ϲ�(������ظ�Ԫ��)     */
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //��La��ͷ�����ΪLc��ͷ��� 
   while(pa && pb){
   if (pa->data == pb->data)
        { pbd=pb; pb = pb->next; delete pbd;}
     else if (pa->data<pb->data)
                 { pc->next=pa;pc=pa;pa=pa->next;}
              else  {pc->next=pb; pc=pb; pb=pb->next;};
   pc->next=pa?pa:pb;    //����ʣ���  
   delete Lb;}             //�ͷ�Lb��ͷ��� 
}













