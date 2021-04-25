#include<iostream>
#include<string>
using namespace std;

string num;

int main()
{
	cin>>num;
	int l=num.length();
	cout<<l<<endl;
	for(int i=0;i<l;i++)
	{
		cout<<num.at(i);
		if(i != l-1)
			cout<<" ";
		else
			cout<<endl;
	}
	for(int i=l-1;i>=0;i--)
		cout<<num.at(i);
	cout<<endl;
	return 0;
}
