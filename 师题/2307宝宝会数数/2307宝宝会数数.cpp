#include<iostream>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};

int fun(int num)
{
	if(num==0)return a[0];
	int ans=0;
	
	while(num)
	{
		ans+=a[num%10];
		num/=10;
	}
	return ans;
}

int main()
{
	int n,ans=0;
	cin>>n;
	
	for(int i=0;i<=n;i++)
	{
		ans+=fun(i);
	}
	cout<<ans<<endl;
	return 0;
} 
