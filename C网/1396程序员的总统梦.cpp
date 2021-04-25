#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int a[105];

int main()
{
	while(scanf("%d",&n)==1 && n!=0)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		sort(a,a+n,less<int>());
		int ans=0;
		for(int i=0;i<(n/2+1);i++)
			ans+=(a[i]/2+1);
		cout<<ans<<endl;	
	}
	return 0;
}
