#include<stdio.h>
#include<iostream.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define TElemType char

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *LChild,*RChild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree T)
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




void main()
{
	BiTree T;
	CreateBiTree(T);
}
