#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;

long long int n;

int main()
{ 
	while(cin>>n && n!=0)
	{
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<ceil(log(n*1.0)/log(3.0))<<endl;			
	}
	return 0;
} 
