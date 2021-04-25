#include<iostream>
using namespace std;

int a[6]={100,50,10,5,2,1};

int fun(int num)
{
	int i=0,ans=0;
	while(num>0)
	{
		ans+=(num/a[i]);
		num%=a[i];
		i++;
	}
	return ans;
}
int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			ans+=fun(t);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
