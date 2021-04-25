#include<iostream>
#include<algorithm>
#include<cstring>
#include<set> 
using namespace std;

typedef long long int ll;

ll n,a[1000000+5];
ll s[1000000+5];

int main()
{	
	cin>>n;
	for(int i=0;i<n;i++)//输入并初始化，每人最少一个橙子 
	{
		cin>>a[i];
		s[i]=1;
	}
	
	for(int i=1;i<n;i++)//从左至右判断 
	{
		if(a[i-1]<a[i] && s[i-1]>=s[i])
			s[i]=s[i-1]+1;		
	}
	for(int i=n-2;i>=0;i--)//从右至左判断 
	{
		if(a[i]>a[i+1] && s[i]<=s[i+1])
			s[i]=s[i+1]+1;		
	}
	
	ll ans=0;
	for(int i=0;i<n;i++)//计算总和 
	{
		ans+=s[i];	
	}
	cout<<ans;
	return 0;
} 
