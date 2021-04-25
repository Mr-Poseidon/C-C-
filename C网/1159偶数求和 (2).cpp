#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

int main()
{
	
	while(cin>>n>>m)
	{
		int num=2;
		bool f=true;
		while(n)
		{
			int sum=0;
			int t=min(m,n);
			for(int i=0;i<t;i++)
			{
				sum+=num;
				num+=2;
			}
			if(f)
			{
				f=false;
			}
			else 
				cout<<" ";
			cout<<sum/t;
			n-=t;
		}
		cout<<endl;
	}
	return 0;
} 
