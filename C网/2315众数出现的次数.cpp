#include<iostream>
#include<map>
using namespace std;

typedef unsigned int ui;

int n;
map<ui,int> num;//first-���ֵ�����second-���ֵĴ��� 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)//���������� 
	{
		ui a,b;
		cin>>a>>b;
		num[a]++;//a���ֵĴ���+1 
		num[(a^b)]++;//a^b���ֵĴ���+1 
	}
	
	ui t=0,ans=0;//t-���ֵĴ�����ans-��� 
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
