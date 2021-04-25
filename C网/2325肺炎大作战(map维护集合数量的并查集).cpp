#include<iostream>
#include<map>
using namespace std;

map<int,int> par;
map<int,int> si;

void init(int x)//初始化 
{
	if(si[x])return;//有被访问过，初始值为1，否则为0 
	
	par[x]=x;
	si[x]=1;
}
int find(int x)//查根 
{
	if(x==par[x])return x;
	else return par[x]=find(par[x]);
}
void merge(int x,int y)//合并 
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
		par.clear();//清空集合 
		si.clear();
		
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			init(a);//初始化 
			init(b);
			merge(a,b);//合并 
		}
		
		int ans=0;
		for(map<int,int>::iterator it=si.begin();it!=si.end();it++)
			ans=max(ans,it->second);
		
		cout<<ans<<endl;	
	}
	return 0;
} 
