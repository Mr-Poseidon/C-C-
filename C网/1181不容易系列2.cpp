#include<iostream>
#include<cstdio>
using namespace std;

int n;

int main()
{
	while(~scanf("%d",&n))
	{
		int ans=1;
		for(int i=1;i<n;i++)
			ans*=i;
		cout<<ans<<endl;
	}
	return 0;
} 
