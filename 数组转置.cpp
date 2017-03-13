#include <stdio.h>
#include <iostream.h>

#define  MAXSIZE 100    //���ķ���Ԫ�ظ���
#define  ElemType int
#define OK  true
#define ERROR false

typedef struct
{
	int i,j;             //����š������
	ElemType e;    //����Ԫ��ֵ
}Triple;

typedef struct 
{
	Triple data[MAXSIZE+1];//�洢����Ԫ�ص�һά����,����data[0]δ��
	int mu,nu,tu;   //������������������Ԫ�ظ���
}TSMatrix;

void Print(TSMatrix &M)//��������Ԫ���ʾ��ϡ�����  

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
{ //������Ԫ���洢��ʾ����ϡ�����M��ת�þ���T
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
{//������Ԫ��˳���洢��ʾ����ϡ�����M��ת�þ���T
	int num[MAXSIZE],cpot[MAXSIZE];
	int col, t, p, q;
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;  
	if(T.tu) 
	{
		for (col=1; col<=M.nu; ++col) num[col]=0;
		for (t=1; t<=M.tu; ++t) ++num[M.data[t].j]; //��M��ÿһ�к�����Ԫ����
		cpot[1]=1; //���col���е�һ������Ԫ��b.data�е����
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
	    printf("������ϡ�����������������ͷ���Ԫ�ظ���\n");
        scanf("%d ,%d ,%d",&M.mu,&M.nu,&M.tu);
		for(int k=1;k<=M.tu;k++)
		{
			printf("������ڸ�%d����Ԫ�ص���Ԫ����Ϣ\n",k);
		    scanf("%d,%d,%d",&M.data[k].i,&M.data[k].j,&M.data[k].e);
		}
		printf("ת��ǰ�ľ���:\n");
        Print(M);
		FastTransposeSMatrix (M,T);
        printf("ת�ú�ľ���:\n");
        Print(T);

}