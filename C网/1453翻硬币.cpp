#include<iostream>
#include<string>
using namespace std;

int a[2][1000];

int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='*')a[0][i]=1;
		else a[0][i]=-1;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='*')a[1][i]=1;
		else a[1][i]=-1;
	
	int step=0;
	for(int i=0;i<s.size();i++)
	{
		if(a[0][i]!=a[1][i])
		{
			a[0][i]*=-1;
			a[0][i+1]*=-1;
			step++;
		}
	}
	cout<<step;
	return 0;
}
