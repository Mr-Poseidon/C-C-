#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a,b,c;

bool fun(int n)
{
	a=n/100;
	b=n/10%10;
	c=n%10;
	if(pow(a,3)+pow(b,3)+pow(c,3)==n)
		return true;
	return false;
} 
int main()
{
	for(int i=100;i<=999;i++)
		if(fun(i))
			cout<<i<<endl;
	return 0;
}
