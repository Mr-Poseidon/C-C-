#include<iostream>
#include<cstdio>
using namespace std;

double x;

int main()
{
	cin>>x;
	if(x<1)
		printf("%.2lf",x);
	else if(x<10)
		printf("%.2lf",2*x-1);
	else
		printf("%.2lf",3*x-11);
	return 0;
}
