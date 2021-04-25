#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string fun(string str)
{
	int l=str.length();
	string ans;
	char ch;
	int num=0,times=0;
	for(int i=0;i<l;i++)
	{
		ch=str.at(i);
		times++;
		while(ch==str[i+1])
		{
			times++;
			i++;
		}
		string t;
		char a[10];
		sprintf(a,"%d",times);
		t=a;
		ans.append(t);
		t=ch;
		ans.append(t);
		times=0;
	}
	return ans; 
}
int main()
{
	int n=0;
	string ans="1",temp;
	cin>>n;
		
	if(n==1)
	{
		cout<<ans;
		return 0; 
	}
	 
	for(int i=2;i<=n;i++)
		ans=fun(ans);
	cout<<ans;
	return 0;
} 
