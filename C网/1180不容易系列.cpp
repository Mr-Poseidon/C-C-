#include<iostream>
using namespace std;

int n;

int fun(int n)
{
	if(n==1)
		return (3-1)*2;
	else
		return (fun(n-1)-1)*2;
}
int main()
{
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		cout<<fun(m)<<endl;
	}
	return 0;
} 
