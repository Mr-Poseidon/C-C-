#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	double t,w;//t-Ê±³¤£¬w-Ê±Ğ½ 
	cin>>t>>w;
	double ans=0;
	
	if(t>40)
	{
		ans+=40*w;
		t-=40;
	}
	else 
	{
		ans+=t*w;
		t-=t;
	}
	
	if(t>10)
	{
		ans+=10*1.5*w;
		t-=10;
	}
	else 
	{
		ans+=t*1.5*w;
		t-=t;
	}
	
	if(t>0)
	{
		ans+=t*2.0*w;
	}
	printf("%.2lf",ans);
	return 0;
} 
