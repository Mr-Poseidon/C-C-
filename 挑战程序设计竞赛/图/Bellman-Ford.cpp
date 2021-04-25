#include<iostream>
#include<cstring>
#define INF 1e7
using namespace std;

struct edge{
	int from,to,cost;
};


edge ed[10000];

int d[10000];
int v,e;

void shortest_path(int s)//��s����������Ȩ�أ������ڸ�Ȩ���� 
{
	for(int i=0;i<v;i++)
		d[i]=INF;
	d[s]=0;
	
	while(1)//һֱ�������бߣ�ֱ�����ٽ����ɳڲ��� 
	{
		bool update=false;
		for(int i=0;i<e;i++)//�������б� 
		{
			edge e=ed[i];
			//��������ڣ��յ�ľ���>������+�ñ�Ȩֵ 
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost)//�ɳڲ��� 
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(update!=true)break;
	}
	return;
}
bool find_negative_loop()//�ж��Ƿ���ڸ�Ȩ�� 
{
	memset(d,0,sizeof(d));
	
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<e;j++)
		{
			edge e=ed[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				if(i==v-1)return true;//�������ֵ�����ڸ�Ȩ�� 
			}	
		}
	}
	return false; 
} 
int main()
{
	return 0;
} 
