#include <stdio.h>
#include <iostream.h>

#define  MAXSIZE 100    //最大的非零元素个数
#define  ElemType int
#define OK  true
#define ERROR false

typedef struct
{
	int i,j;             //行序号、列序号
	ElemType e;    //非零元素值
}Triple;

typedef struct 
{
	Triple data[MAXSIZE+1];//存储非零元素的一维数组,其中data[0]未用
	int mu,nu,tu;   //总行数、列数及非零元素个数
}TSMatrix;

void Print(TSMatrix &M)//输出输出三元组表示的稀疏矩阵  

{
	int p,i,j;
	for (p=1,i=1; i<=M.mu; i++) 
	{
		for (j=1; j<=M.nu; j++)
			if (p<=M.tu&&M.data[p].i==i&& M.data[p].j==j) cout<<M.data[p++].e;
			else cout<<0;
		cout<<endl;
	}
}

bool TransposeSMatrix (TSMatrix &M,TSMatrix &T)
{ //采用三元组表存储表示，求稀疏矩阵M的转置矩阵T
	int col, q;
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	if(T.tu)
	{	
		q=1;
		for(col=1; col<=M.nu; ++col)
		
			for(int p=1; p<=M.tu; ++p)
			
				if (M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i; 
					T.data[q].e=M.data[p].e;
					++q;
				}
			
		
	}
	return OK;
} 

int FastTransposeSMatrix (TSMatrix &M,TSMatrix &T) 
{//采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
	int num[MAXSIZE],cpot[MAXSIZE];
	int col, t, p, q;
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;  
	if(T.tu) 
	{
		for (col=1; col<=M.nu; ++col) num[col]=0;
		for (t=1; t<=M.tu; ++t) ++num[M.data[t].j]; //求M中每一列含非零元个数
		cpot[1]=1; //求第col列中第一个非零元在b.data中的序号
		for(col=2; col<=M.nu; ++col)
		{
			cpot[col]=cpot[col-1]+num[col-1];
		}
		for(p=1; p<=M.tu; ++p)
		{ 
			col=M.data[p].j; q=cpot[col];
			T.data[q].i=M.data[p].j; 
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e; ++cpot[col];
		}//for
	} //if
	return OK;
}


void main()
{
	    TSMatrix M,T;
	    printf("请输入稀疏矩阵的行数、列数和非零元素个数\n");
        scanf("%d ,%d ,%d",&M.mu,&M.nu,&M.tu);
		for(int k=1;k<=M.tu;k++)
		{
			printf("请输入第个%d非零元素的三元组信息\n",k);
		    scanf("%d,%d,%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
		}
		printf("转置前的矩阵:\n");
        Print(M);
		FastTransposeSMatrix (M,T);
        printf("转置后的矩阵:\n");
        Print(T);

}