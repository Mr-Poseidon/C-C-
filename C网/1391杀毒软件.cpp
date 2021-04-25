#include<iostream>
#include<algorithm>
using namespace std;

int n,a[105];

int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,greater<int>());
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
