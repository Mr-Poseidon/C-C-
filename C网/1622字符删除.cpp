#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s,ans;
	char ch;
	cin>>s>>ch;
	for(int i=0;i<s.size();i++)
		if(s[i]!=ch)ans+=s[i];
	cout<<ans;
	return 0;
}
