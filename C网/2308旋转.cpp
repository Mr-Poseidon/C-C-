#include<iostream>
using namespace std;

int a[105][105];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<m;i++)
	{
		if(i)
			cout<<endl;
		for(int j=n-1;j>=0;j--)
		{
			cout<<a[j][i];
			if(j)cout<<" ";
		}
	}
	return 0;
} 
