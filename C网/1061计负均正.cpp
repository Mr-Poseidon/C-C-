#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int posi=0,nega=0,posi_sum=0;
	for(int i=0;i<20;i++)
	{
		int t;
		cin>>t;
		if(t>0)
		{
			posi++;
			posi_sum+=t;
		}
		else
			nega++;
	}
	printf("%d\n%.2lf",nega,(double)posi_sum/posi);
	return 0;
}
 
