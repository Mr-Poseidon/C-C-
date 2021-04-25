#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int n,m,a[15];

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		ll ans=1;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		
		int l=0,r=n-1;
		while(m)
		{
			if(m%2==1)
			{
				ans*=a[r];
				r--;
				m--;
				continue;
			}
			else
			{
				if(a[l]*a[l+1]>a[r]*a[r-1])
				{
					ans*=(a[l]*a[l+1]);
					l+=2;
				}
				else
				{
					ans*=(a[r]*a[r-1]);
					r-=2;
				}
				m-=2;
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
