#include<iostream>
using namespace std;

int n,a,b;

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		cout<<(a+b)%100<<endl;
	}
	return 0;
} 
