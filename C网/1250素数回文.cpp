#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool is_prime(int num)//是素数 
{
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return false;
	return true;
}
bool is_palindrome(int num)//是回文数 
{
	string s;
	while(num){
		s+=(char)(num%10+'0');
		num/=10;
	}
	for(int i=0,j=s.length()-1;i<=j;i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;
}
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(is_prime(i))
			if(is_palindrome(i))
				cout<<i<<endl;
	}
	return 0;
} 
