#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int n,a,b;
//优先选取战斗力大的豪杰，平均值最大 
priority_queue< int,vector<int>,less<int> > f;//豪杰战斗力 
double ans=0;

int main()
{
	cin>>n>>a>>b;
	if(a>b)//a必须小于b，平均值最大 
	{
		int t=a;
		a=b;
		b=t;
	}
	for(int i=0;i<n;i++)//输入各豪杰战斗力 
	{
		int t;
		cin>>t;
		f.push(t);
	}
		
	
	int sum=0;
	for(int i=0;i<a;i++)//计算a城平均值 
	{
		sum+=f.top();
		f.pop();
	}
	ans+=(sum*1.0/a);
	
	sum=0;
	for(int i=0;i<b;i++)//计算b城平均值 
	{
		sum+=f.top();
		f.pop();
	}
	ans+=(sum*1.0/b);
	
	printf("%.6lf",ans);
	return 0;
} 
