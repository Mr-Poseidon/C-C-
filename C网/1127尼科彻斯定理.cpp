#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,ans;
	cin>>n;
	ans=n*n-n+1;
	printf("%d*%d*%d=%d=",n,n,n,n*n*n);
	for(int i=0;i<n;i++)
	{
		if(i)cout<<"+";
		cout<<ans;
		ans+=2;
	}
	return 0;
}
