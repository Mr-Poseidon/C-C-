#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


struct good{
	double w,vi;//w-重量，vi-价值密度 
};
bool cmp(good a,good b){
	return a.vi>b.vi;
}

good g[10000];
double ans=0;
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		double w,v;
		cin>>w>>v;
		g[i].vi=v/w;
		g[i].w=w;
	}
	sort(g,g+n,cmp);
	
	int i=0;
	while(m)
	{
		ans+=min((int)g[i].w,m)*g[i].vi;
		m-=min((int)g[i].w,m);
		i++;
		if(i==n)break;
	}
	printf("%.1lf",ans);
	return 0; 
}
