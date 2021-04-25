#include<iostream>
#include<cstdio>
using namespace std;

int a,b;

int main()
{
	while(cin>>a>>b && a!=0 && b!=0)
	{
		a*=100;
		int t=0;
		for(int i=0;i<100;i++)
		{
			if((a+i)%b==0)
			{
				if(t)
					cout<<" ";
				printf("%02d",i);//注意末两位首位为0的情况 
				t++;
			}
		}
		cout<<endl;
	}
	return 0;
} 
