#include<iostream>
#include<cstdio>
using namespace std;

int n,k=0;
int map[1001]={0};

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		map[t]=1;
	}
	for(int i=0;i<=1000;i++)
		if(map[i])
			k++;
	cout<<k<<endl;
	k=0;
	for(int i=0;i<=1000;i++)
		if(map[i])
		{
			if(k)cout<<" ";
			cout<<i;
			k++;
		}
	return 0;
}
