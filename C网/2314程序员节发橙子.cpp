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
	for(int i=0;i<n;i++)//���벢��ʼ����ÿ������һ������ 
	{
		cin>>a[i];
		s[i]=1;
	}
	
	for(int i=1;i<n;i++)//���������ж� 
	{
		if(a[i-1]<a[i] && s[i-1]>=s[i])
			s[i]=s[i-1]+1;		
	}
	for(int i=n-2;i>=0;i--)//���������ж� 
	{
		if(a[i]>a[i+1] && s[i]<=s[i+1])
			s[i]=s[i+1]+1;		
	}
	
	ll ans=0;
	for(int i=0;i<n;i++)//�����ܺ� 
	{
		ans+=s[i];	
	}
	cout<<ans;
	return 0;
} 
