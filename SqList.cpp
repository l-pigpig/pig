#include<iostream.h>
#include<stdio.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 0
#define ERROR 1
#define TRUE true
#define FALSE false
#define ElemType int

typedef struct 
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//初始化线性表L
int InitList_Sq (SqList &L)
{  
  	L.elem=(ElemType*)malloc(LIST_INIT_SIZE *sizeof(ElemType));  //分配空间
  	if (!L.elem)  return ERROR ; 
	L.length=0; //将当前线性表长度置0
	L.listsize=LIST_INIT_SIZE;
  	return OK; //成功返回OK
}

//销毁线性表L
void DestroyList_Sq (SqList &L)
{
	if (L.elem) free(L.elem); //释放线性表的存储空间
	L.elem=NULL;
	L.length=0;
	L.listsize=0;
}

//清空线性表L
void ClearList_Sq (SqList &L) 
{
	L.length=0; //将线性表的长度置为0
}

//求线性表L的长度
int ListLength_Sq (SqList L)
{
  	 return (L.length);             
}

//判断线性表L是否为空
int ListEmpty_Sq (SqList L)
{
  	if (L.length==0) return TRUE;      
   	else return FALSE;
}


 //获取线性表L中的某个数据元素的内容
int GetElem_Sq (SqList L, int i, ElemType *e)
{
 	if (i<0||i>=L.length) return ERROR; 
	*e=L.elem[i]; return *e;
}

//在线性表L中检索值为e的第一个数据元素
int LocateElem_Sq (SqList L, ElemType *e)
{  
	for (int i=0; i< L.length; i++)
    		if (L.elem[i]==*e)  return i;                
  	return -1;
}

//在线性表L中下标为i的数据元素之前插入数据元素e 
int ListInsert_Sq (SqList &L, int i, ElemType e)     
{
  	if (L.length==L.listsize) return ERROR ; 
	if (i<0 || i-1>L.length) return ERROR; 
	for (int j=L.length-1; j>=i; j--) 
		L.elem[j+1] = L.elem[j];
  	L.elem[i]=e;
	++L.length; 
	return OK;
}

/*int ListInsert_Sq (SqList &L, int i, ElemType e) 
{
	ElemType *p,*q;
	if(i<1 || i>L.length+1) return ERROR;
	if(L.length >= L.listsize)
	{
		L.elem = (ElemType*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT) *sizeof(ElemType));
		if(!L.elem) return ERROR;
		L.listsize+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
  for(p=&(L.elem[L.length-1]);p>=q;--p)
  {
	  *(p+1)=*p;
  }
  *q=e;
  ++L.length;
  return OK;

}*/

//将线性表L中第i个数据元素删除
int ListDelete_Sq(SqList &L, int i, ElemType *e)
{
  	if (ListEmpty_Sq (L)) return ERROR; 
	if (i<0||i>=L.length) return ERROR; 
	*e=L.elem[i]; 
  	for (int j=i+1; j<=L.length-1; j++) 
		L.elem[j-1]=L.elem[j];
  	L.length--; 
	return 0;
}

//已知线性表La和Lc的元素按照非降序排列，将线性表La和Lb合并到Lc，使得Lc的元素按照非降序排列
int MergeList_Sq (SqList La, SqList Lb, SqList &Lc)
{
 	ElemType  *pa, *pb, *pc, *pa_last, *pb_last; 
	pa=La.elem; pb=Lb.elem; 
	Lc.listsize=La.listsize+Lb.listsize;
	Lc.length=La.length+Lb.length;
	pc=Lc.elem=(ElemType*)malloc (Lc.listsize*sizeof(ElemType));
	if(!Lc.elem) return ERROR;
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<pb_last)
	{
		if(*pa<=*pb) {*pc=*pa; pc++; pa++;}
		else{*pc=*pb; pc++; pb++;}
	}
	while(pa<=pa_last){*pc=*pa; pc++; pa++;}
	while(pb<=pb_last){*pc=*pb; pc++; pb++;}
}


void union1(SqList &la,SqList lb)
{
	ElemType *e;
	int la_len=ListLength_Sq(la);
	int lb_len=ListLength_Sq(lb);
	for(int i=1;i<=lb_len;i++)
	{
		GetElem_Sq(lb,i,e);
		if(!LocateElem_Sq(la,e)) ListInsert_Sq(la,++lb.length,*e);
	}

}

int main()
{
	SqList la,lb;
	ElemType *e;
	int i;
	InitList_Sq (la);
	InitList_Sq (lb);
	ListInsert_Sq (la, 1, 3);
	ListInsert_Sq (la, 2, 5);
	ListInsert_Sq (la, 3, 8);
	ListInsert_Sq (la, 4, 11);
	cout<<"la={";
	for(i=0;i<7;i++)
	{
		cout<<GetElem_Sq (la, i,e)<<" ";
	}
	cout<<"}"<<endl;

	ListInsert_Sq (lb, 1, 2);
	ListInsert_Sq (lb, 2, 6);
	ListInsert_Sq (lb, 3, 8);
	ListInsert_Sq (lb, 4, 9);
	ListInsert_Sq (lb, 5, 11);
	ListInsert_Sq (lb, 6, 15);
	ListInsert_Sq (lb, 7, 20);
	union1(la,lb);
	cout<<"la={";
	for(i=0;i<10;i++)
	{
		cout<<GetElem_Sq (la, i,e)<<" ";
	}
	cout<<"}"<<endl;
	return 0;
} 






1 3 4 8 9
2 5 7 8 9 11 17