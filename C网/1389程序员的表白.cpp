#include<iostream>
using namespace std;

int n;

int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=n+2;j++)
			{
				if(i==n+1)cout<<"*";
				else if(j==1 || j==n+2)cout<<"*";
				else cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;		
	}
	return 0;
} 
