#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int n,a,b;
//����ѡȡս������ĺ��ܣ�ƽ��ֵ��� 
priority_queue< int,vector<int>,less<int> > f;//����ս���� 
double ans=0;

int main()
{
	cin>>n>>a>>b;
	if(a>b)//a����С��b��ƽ��ֵ��� 
	{
		int t=a;
		a=b;
		b=t;
	}
	for(int i=0;i<n;i++)//���������ս���� 
	{
		int t;
		cin>>t;
		f.push(t);
	}
		
	
	int sum=0;
	for(int i=0;i<a;i++)//����a��ƽ��ֵ 
	{
		sum+=f.top();
		f.pop();
	}
	ans+=(sum*1.0/a);
	
	sum=0;
	for(int i=0;i<b;i++)//����b��ƽ��ֵ 
	{
		sum+=f.top();
		f.pop();
	}
	ans+=(sum*1.0/b);
	
	printf("%.6lf",ans);
	return 0;
} 
