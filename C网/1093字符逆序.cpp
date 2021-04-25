#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

char ch;
string ans;

string invert(string str)
{
	int i=0,j=str.length()-1;
	while(i<j)
	{
		char t;
		t=str.at(i);
		str.at(i)=str.at(j);
		str.at(j)=t;
		i++;
		j--;
	}
	return str;
	
}
int main()
{
	while(~scanf("%c",&ch) && ch!='\n')
		ans.append(1,ch);
	ans=invert(ans);
	cout<<ans<<endl;
	return 0;
}
