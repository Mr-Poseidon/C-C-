#include<iostream>
using namespace std;

int n,ans=0;

bool is_seven(int num)
{
	while(num)
	{
		if(num%10==7)return true;
		num/=10;
	}
	return false;
}
int main()
{
	cin>>n;
	for(int i=7;i<=n;i++)
	{
		if(is_seven(i))
		{
			ans++;
			continue;
		}
		if(i%7==0)
		{
			ans++;
			continue;
		}
	}
	cout<<ans;
	return 0;
} 
