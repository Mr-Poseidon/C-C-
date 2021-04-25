#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,ans[1005],t;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ans[i];
	sort(ans,ans+n,greater<int>());
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<ans[i];
	}
	return 0;
}
