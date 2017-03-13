#include<stdio.h>
#include<iostream.h>
#include<malloc.h>
#include<math.h>

#define ERROR false
#define OK true
#define SElemType int
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return ERROR;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

int GetTop(SqStack &S,SElemType &e)
{
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
}

int Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT) * sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++ =e;
	//*S.top=e
	//S.top++
	return e;
}

SElemType Pop(SqStack &S,SElemType e)
{
	if(S.top==S.base) return ERROR;
	e=*(--S.top);
	return e;
}

bool StackEmpty(SqStack S)
{
	if(S.top==S.base) return true;
	else return false;
}

//对于输入的任意一个非负十进制整数，打印输入与其对等的八进制数
void conversion()
{
	SqStack S;
	InitStack(S);
	SElemType e;
	int N;
	cout<<"输入一个数：";
	cin>>N;
	while(N)
	{
		
		Push(S,N%8);
		N=N/8;
	}
	cout<<"输出八进制数：";
	while(!StackEmpty(S))
	{
		e=Pop(S,e);
		cout<<e;
	}
	cout<<endl;

}
void main()
{
	conversion();

}