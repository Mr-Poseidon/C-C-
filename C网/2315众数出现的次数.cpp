#include<iostream>
#include<map>
using namespace std;

typedef unsigned int ui;

int n;
map<ui,int> num;//first-出现的数，second-出现的次数 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)//输入两个数 
	{
		ui a,b;
		cin>>a>>b;
		num[a]++;//a出现的次数+1 
		num[(a^b)]++;//a^b出现的次数+1 
	}
	
	ui t=0,ans=0;//t-出现的次数，ans-结果 
	for(map<ui,int>::iterator it=num.begin();it!=num.end();it++)
	{
		if(it->second > t)
		{
			t=it->second;
			ans=it->first;
		}
	}
	cout<<ans;
	return 0;
} 
