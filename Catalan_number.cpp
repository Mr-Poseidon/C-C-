#include<iostream>
using namespace std;

long long int a[1005]={1,1};//卡特兰数模1e9+7的序列 
int mod=1e9+7;

int main()
{
	for(int i=2;i<=1000;i++)
	{
		a[i]=a[i-1]*(4*i-2)/(i+1);//计算卡特兰数 
		a[i]%=mod; 
	}
	for(int i=0;i<=1000;i++)cout<<a[i]<<endl;
	return 0;
	
} 
