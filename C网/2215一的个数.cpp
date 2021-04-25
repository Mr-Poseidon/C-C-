#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int getOne(int num)
{
	char s[100]={'\n'};
	int ans=0;
	sprintf(s,"%d",num);
	for(int i=0;i<strlen(s);i++)
		if(s[i]=='1')
			ans++;
	return ans;
}
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		ans+=getOne(i);
	cout<<ans;
	return 0;
} 
