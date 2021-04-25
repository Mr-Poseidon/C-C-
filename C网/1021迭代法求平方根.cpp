/*
首项必为x1=a/2
求a的平方根的迭代公式为： X[n+1]=(X[n]+a/X[n])/2
假设a=9 :
    x1=9/2=4.5; 
    x2=(4.5+9/4.5)/2=3.25   4.5-3.25>0.00001
    x3=(3.25+9/3.25)/2=3.00962   3.25-3.00962>0.00001
    x4=(3.00962+9/3.00962)/2=3.00002   3.00962-3.00002>0.00001
*/


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double num;
	cin>>num;
	double a=num/2.0,b;
	while(1)
	{
		b = ( a + num / a ) / 2;
		if(fabs(b-a)<0.00001)
		{
			printf("%.3lf",b);
			break;
		}
		a=b;
	}
	return 0;
}
