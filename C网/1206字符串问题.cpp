#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a;
	cin>>a;
	cout<<string(a.rbegin(),a.rend());
	return 0;
} 
