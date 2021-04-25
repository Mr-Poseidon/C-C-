#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	if(a.size()!=b.size())
	{
		cout<<1;
		return 0;
	}
	else if(a==b)
	{
		cout<<2;
		return 0;
	}
	else if(a.size()==b.size())
	{
		for(int i=0;i<a.size();i++)
			if(tolower(a[i])!=tolower(b[i]))
			{
				cout<<4;
				return 0;
			}
		cout<<3;
		return 0;
	}
	return 0;
} 
