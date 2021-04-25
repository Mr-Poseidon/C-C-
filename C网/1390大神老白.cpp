#include<iostream>
#include<cmath>
using namespace std;

typedef long long int ll;

int n;

int main()
{
	while(cin>>n)
	{
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			ans+=abs(t);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
