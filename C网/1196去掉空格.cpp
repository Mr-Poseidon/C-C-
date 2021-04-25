#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s,ans;
	while(getline(cin,s))
	{
		for(int i=0;i<s.length();i++)
			if(s[i]==' ')
				continue;
			else
				ans+=s[i];
		cout<<ans<<endl;
		ans.clear();
	}
	return 0;
} 
