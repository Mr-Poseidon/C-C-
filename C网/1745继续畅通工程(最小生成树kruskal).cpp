#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
	int v1,v2,cost;
};
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}

int par[105];
int n,cot;
vector<edge> E;

void init(int n)//��ʼ�����鼯 
{
	E.clear();
	cot=0;
	for(int i=0;i<=n;i++)par[i]=i;
}
int find(int x)//��� 
{
	if(x==par[x])return x;
	else return par[x]=find(par[x]);
}
bool same(int a,int b)//�Ƿ�ͬ�� 
{
	return find(a)==find(b);
}
void merge(int a,int b)//�ϲ� 
{
	a=find(a);
	b=find(b);
	if(a==b)return;
	
	par[b]=a;
	cot--; 
}

int kruskal()//kruskal�㷨 
{
	sort(E.begin(),E.end(),cmp);//���� 
	int ans=0;//�������Ŀ��� 
	
	for(int i=0;i<E.size();i++)
	{
		if(!same(E[i].v1,E[i].v2))//�ж��Ƿ�ͬ�� 
		{
			merge(E[i].v1,E[i].v2);//�ϲ� 
			ans+=E[i].cost;//���Ͽ��� 
		}
		if(cot==1)break;//��ͨ��Ϊ1˵��ȫ����ͨ 
	}
	return ans;
}

int main()
{
	while(cin>>n && n!=0)
	{
		init(n);//��ʼ�� 
		
		 for(int i=0;i<n*(n-1)/2;i++)//���� 
		{
			edge t;
			int f;
			cin>>t.v1>>t.v2>>t.cost>>f;
			if(f==1)
				merge(t.v1,t.v2);
			else
				E.push_back(t);	
		}
		cout<<kruskal()<<endl;
	}
	
	return 0;
}
