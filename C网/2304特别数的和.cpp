#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 

bool is_have(int num)
{
	char s[10]={'\0'};
	sprintf(s,"%d",num);
	for(int i=0;i<strlen(s);i++)
		if(s[i]=='2' || s[i]=='0' || s[i]=='1' || s[i]=='9')
			return true;
	return false;
	
} 
int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(is_have(i))
			ans+=i;
	}
	cout<<ans;
	return 0;
}
