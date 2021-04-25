#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

unsigned int a,b,t,maxfac;

int main()
{
	cin>>a>>b;
	t=min(a,b);
	for(int i=t;i>0;i--)
	{
		if(a%i==0 && b%i==0)
		{
			maxfac=i;
			break;
		}		
	}
	cout<<a*b/maxfac<<endl;
	return 0;
}
