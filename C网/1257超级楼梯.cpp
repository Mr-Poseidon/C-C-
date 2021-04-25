#include<iostream>
using namespace std;

int fun(int n)
{
	if(n<0)return 0;
	if(n==0)return 1;
	return fun(n-1)+fun(n-2);
}
int main()
{
	int cas,n;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		cout<<fun(n-1)<<endl;
	}
	return 0;
} 
