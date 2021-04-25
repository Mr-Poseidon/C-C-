#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[2][3];

int main()
{
	cin>>n; 
	while(n--)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<3;j++)
				cin>>a[i][j];
		for(int i=2;i>0;i--)
		{
			
			a[0][i-1]+=(a[0][i]+a[1][i])/60;
			a[0][i]=(a[0][i]+a[1][i])%60;
		}
		a[0][0]+=a[1][0];
		cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[0][2]<<endl;
	} 
	return 0;
} 
