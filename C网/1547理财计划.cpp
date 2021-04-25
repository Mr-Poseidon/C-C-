#include<iostream>
#include<cstdio>
using namespace std;

int k,n;
double p,ans=0;

int main()
{
	cin>>k>>n>>p;
	double mon=0;
	for(int i=1;i<=n;i++)
	{
		mon+=k;
		mon+=mon*p;			
	}
	printf("%.2lf",mon-k*n-0.005); 
	return 0;
}
