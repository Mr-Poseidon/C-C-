#include<iostream>
using namespace std;

int par[100000];//���� 
int rank[100000];//������� 

void init(int n)//��ʼ�� 
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}	
}

int find(int x)//��ѯ���ĸ� 
{
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y)//�ϲ�x��y�������� 
{
	x=find(x);
	y=find(y);
	if(x==y)return; 
	
	if(rank[x]<rank[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
} 

bool same(int x,int y)//�ж��Ƿ�ͬһ������ 
{
	return find(x)==find(y);
}

int main()
{
	return 0; 
} 
