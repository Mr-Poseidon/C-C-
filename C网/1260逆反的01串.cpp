#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')s[i]='0';
			else s[i]='1';
		}
		cout<<s<<endl;
	}
	return 0;
} 
