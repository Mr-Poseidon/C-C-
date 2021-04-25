#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double a,b,c,d;

int main()
{
	while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)==4)
	{
		printf("%.2lf\n",sqrt( pow( a-c,2 ) + pow( b-d,2 ) ));
	}
	return 0;
}
