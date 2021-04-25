#include<iostream>
using namespace std;

int n;

int main()
{
	cin>>n;
	while(n--)
	{
		int t;
		cin>>t;
		if(t%2==0)cout<<4<<endl;
		else cout<<t+3<<endl;
	}
	return 0;
} 
