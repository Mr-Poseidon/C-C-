#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int ans=0;

int main()
{
	string s;
	while(getline(cin,s))
	{
		if(s[s.size()-1]=='?')continue;
		int a,b,c;
		char ch;
		sscanf(s.c_str(),"%d%c%d=%d",&a,&ch,&b,&c);
		
		if(ch=='+')
			if(a+b==c)
				ans++;

		if(ch=='-')
			if(a-b==c)
				ans++;

	}
	cout<<ans;
	return 0;
} 
