#include<stdio.h>
#include<iostream.h>
#include<malloc.h>

#define ERROR 0
#define OK 1
#define TElemType char

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *LChild,*RChild;
}*BiTree;

/*BiTree CreateBiTree()
{
	BiTree T;
	char ch=getchar();
	if(ch=='#') T=NULL;
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=ch;
		T->LChild=CreateBiTree();
		T->RChild=CreateBiTree();
	}
	return T;
}*/

int CreateBiTree(BiTree &T)
{
	char ch=getchar();
	if(ch=='#') T=NULL;
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTNode)))) return ERROR;
		T->data=ch;
        CreateBiTree(T->LChild);
		CreateBiTree(T->RChild);
	}
	return OK;
}

void Visit(BiTree T)
{
	cout<<T->data;
}

void PreOrder(BiTree T)
{
	if(T)
	{
		Visit(T);
	    PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}


void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->LChild);
		Visit(T);
		InOrder(T->RChild);
	}
}


void PostOrder(BiTree T)
{
	if(T)
	{
		PostOrder(T->LChild);
		PostOrder(T->RChild);	
		Visit(T);
	}
}


void main()
{
	BiTree T;
	CreateBiTree(T);
	cout<<"该二叉树的先序遍历为：";
	PreOrder(T);
	cout<<endl;
	cout<<"该二叉树的中序遍历为：";
	InOrder(T);
	cout<<endl;
	cout<<"该二叉树的后序遍历为：";
	PostOrder(T);
	cout<<endl;
}