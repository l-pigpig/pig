#include<stdio.h>
#include<iostream.h>
#include<malloc.h>

#define ElemType int
#define OK  true
#define ERROR false

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(L)
	{
		L->next=NULL;
		return OK;
	}
	else ERROR;
}
//逆序创建
void CreateList_L(LinkList &L,int n)
{
	LNode *p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cout<<"请输入数据：";
	for(int i=n;i>0;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}
//顺序创建
void CreateList_L2(LinkList &L,int n)
{
	LNode *p,*r;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r=L;
	cout<<"请输入数据：";
	for(int i=n;i>0;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		cin>>p->data;
		p->next=r->next;
		r->next=p;
		r=p;
	}
}

void Print(LinkList &L)
{
	LNode *p;
	p=L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void main()
{
	LinkList La;
	CreateList_L(La,3);
	Print(La);
	CreateList_L2(La,3);
	Print(La);

}