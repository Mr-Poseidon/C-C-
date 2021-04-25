#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int n,a,b,c;

int main()
{
	cin>>n;
	a=n/100;
	b=n/10%10;
	c=n%10;
	if(pow(a,3)+pow(b,3)+pow(c,3)==n)
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}
