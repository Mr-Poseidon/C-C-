#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,a,b,t,l=0,r=0,steps=99999999,dif=0;
int differ[11]={0};
//differ0-10分别代表-5,-4,-3,-2,-1,0,1,2,3,4,5的数量 

bool compare(int a,int b)
{return a>b?true:false;}

int dfs(int differ[11],int val,int num,int pre_dif,int step)
{
	if(pre_dif==0)
	{
		steps=min(steps,step);
		return 0;
	}
	if(val>=6)return 0;
	if(num<0)return 0;
	
	for(int i=0;i<=num;i++)
	{
		dfs(differ,val+1,differ[val+5],pre_dif+(-2)*i*val,step+i);
	}
	return 0;
	
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		int t=a-b;
		dif+=t;
		differ[t+5]++;
	}
	if(dif==0)cout<<0<<endl;
	dfs(differ,-5,differ[0],dif,0);
	cout<<steps<<endl;
	/*
	for(int i=0;i<11;i++)
		cout<<i-5<<": "<<differ[i]<<endl;
	*/
	return 0;
}

