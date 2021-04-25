#include<iostream>
using namespace std;

int n;
int dp[32][32]={0,1};

int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)//构造三角形 
			for(int j=1;j<=i;j++)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
				
		for(int i=1;i<=n;i++)//输出 
		{
			for(int j=1;j<=i;j++)
			{
				if(j!=1)
					cout<<" ";
				cout<<dp[i][j];
			}
			cout<<endl;
		}
		cout<<endl;		
	}
	return 0;
}
