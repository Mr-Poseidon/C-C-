#include<iostream>
#include<map>
using namespace std;

map<int,int> par;
map<int,int> si;

void init(int x)//��ʼ�� 
{
	if(si[x])return;//�б����ʹ�����ʼֵΪ1������Ϊ0 
	
	par[x]=x;
	si[x]=1;
}
int find(int x)//��� 
{
	if(x==par[x])return x;
	else return par[x]=find(par[x]);
}
void merge(int x,int y)//�ϲ� 
{
	x=find(x);
	y=find(y);
	if(x==y)return;
	
	par[y]=x;
	si[x]+=si[y];
}
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		par.clear();//��ռ��� 
		si.clear();
		
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			init(a);//��ʼ�� 
			init(b);
			merge(a,b);//�ϲ� 
		}
		
		int ans=0;
		for(map<int,int>::iterator it=si.begin();it!=si.end();it++)
			ans=max(ans,it->second);
		
		cout<<ans<<endl;	
	}
	return 0;
} 
