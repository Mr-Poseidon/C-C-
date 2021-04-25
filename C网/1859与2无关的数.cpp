#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool fun(int n)
{
	while(n)
	{
		if(n%10==2)return true;
		n/=10;
	}
	return false;
} 

int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0 || fun(i))continue;
		ans+=i;
	}
	cout<<ans;
	return 0;
} 
