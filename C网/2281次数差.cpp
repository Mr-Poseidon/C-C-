#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int a[26]={0};

int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[s[i]-'a']++;
	
	int maxn=-9999,minn=9999;
	for(int i=0;i<26;i++)
	{
		if(a[i]==0)continue;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	cout<<maxn-minn<<endl;
	return 0;
} 
