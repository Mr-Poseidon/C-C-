#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
bool is_palindrome(int n)
{
	char s[7];
	sprintf(s,"%d",n);
	int i=0,j=strlen(s)-1;
	while(i<j)
	{
		if(s[i]!=s[j])return false;
		i++;
		j--;
	}
	return true;
}
bool is_n(int num)
{
	int sum=0;
	while(num)
	{
		sum+=(num%10);
		num/=10;
	}
	if(sum==n)return true;
	else return false;
}
int main()
{
	cin>>n;
	bool f=false;
	for(int i=10000;i<1000000;i++)
	{
		if(is_palindrome(i) && is_n(i))
		{
			if(f)cout<<endl;
			cout<<i;
			f=true;
		}	
	}
	if(f==false)cout<<-1;
	return 0;
} 
