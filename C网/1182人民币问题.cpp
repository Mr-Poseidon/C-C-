#include<iostream>
using namespace std;

int num,ans=0; 

int main()
{
	cin>>num;//面值 
	int a=num-8;//保证每个面值都有一张 
	for(int i=0;i<=a/5;i++)//计算5元可取的张数 
	{
		int b=a-i*5;
		for(int j=0;j<=b/2;j++)//计算2元可取的张数(可优化) 
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
