#include<iostream>
using namespace std;

int num[1005];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		swap(num[a-1],num[b-1]);
	}
	for(int i=0;i<n;i++)
		cout<<num[i]<<endl;
	return 0;
} 
