#include<iostream>
#include<cstdio>
using namespace std;

int n;

int main()
{
	int a=1;
	int b=1;
	cin>>n;
	
	if(n<30)
	{
		for(int i=1;i<n;i++)
		{
			int t=a+b;
			b=a;
			a=t;
			//printf("%.8lf\n",(double)b/a);
		}
		printf("%.8lf",(double)b/a);
	}
	else
		printf("%.8lf",0.61803399);//n>20后结果不变 
	
	return 0;
} 
