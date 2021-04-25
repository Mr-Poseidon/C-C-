#include<iostream>
using namespace std;

int main()
{
	unsigned long int n,t=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		t*=i;
		ans+=t;
	}
	cout<<ans<<endl;
	return 0;
}
