#include<iostream>
#include<cstdio> 
using namespace std;

int n,m;
 
int main()
{ 
	cin>>n>>m;
	if(n==0 || m==0)return 0;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(j)cout<<"-";
			cout<<"+";
		}
		cout<<endl;
		if(i<n)
		{
			for(int j=0;j<m+1;j++)
			{
				if(j)cout<<" ";
				cout<<"|";
			}
			cout<<endl;
		}
			
	}
	return 0;
} 
