#include<iostream>
using namespace std;

long long int a[1005]={1,1};//��������ģ1e9+7������ 
int mod=1e9+7;

int main()
{
	for(int i=2;i<=1000;i++)
	{
		a[i]=a[i-1]*(4*i-2)/(i+1);//���㿨������ 
		a[i]%=mod; 
	}
	for(int i=0;i<=1000;i++)cout<<a[i]<<endl;
	return 0;
	
} 
