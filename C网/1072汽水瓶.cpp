#include<iostream>
#include<cstdio>
using namespace std;

int n;

int main()
{
	while(~scanf("%d",&n) && n!=0)
	{
		int ans=0;
		while(n>2)
		{
			int drink;
			drink=n/3;
			n%=3;
			ans+=drink;
			n+=drink;
		}
		if(n==2)ans++;
		cout<<ans<<endl;
	}
	return 0;
} 
