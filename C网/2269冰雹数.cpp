/* 
//朴素 
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

ll fun(ll n)
{
	ll ans=-1;
	while(n!=1)
	{
		ans=max(ans,n);
		n = (n&1) ? n*3+1 : n/2 ;
	}
	return ans;
}
int main()
{
	ll n,ans=-1;
	cin>>n;
	for(int i=n;i>=1;i--)
		ans=max(ans,fun(i));
	cout<<ans;
	return 0;
} 
*/ 



//优化 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef unsigned long long int ull;

ull n,ans;
int a[1000005];

ull max(ull a,ull b)
{
	return a>b?a:b;
}
ull fun(ull n)
{
	ull ans=n;
	while(1)
	{
		while(!(n&1))//偶数除2 
		{
			if(n<1000005)
				a[n]=1;
			n>>=1;
		}
		if(n==1)break;
		n=n*3+1;//奇数 
		if(n<1000005)
			a[n]=1;
		ans=max(ans,n);
	}
	return ans;
}

int main()
{
	ans=0;
	memset(a,0,sizeof(a));
	
	cin>>n;
	for(int i=n;i>=1;i--)//遍历n以内的数 
	{
		if(a[i])//出现的数字不再走 
			continue;
		ans=max(ans,fun(i));
	}
	cout<<ans;
	return 0;
} 

