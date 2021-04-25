#include<iostream>
using namespace std;

long long int fun(long long int n)
{
	int ans=0;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int main()
{
	long long int n;
	while(cin>>n)
	{
		cout<<fun(n)<<endl;
	}
	return 0;
} 
