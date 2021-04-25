#include<iostream>
using namespace std;

typedef long long int ll;

int n,m,K;
int a[52][52]={0};//存每个点的价值 
ll dp[52][52][13][13]={0};
int mod=1e9+7;

int main()
{
	cin>>n>>m>>K;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	
	for(int i=1;i<=n;i++)//行遍历 
		for(int j=1;j<=m;j++)//列遍历 
			for(int k=0;k<=K;k++)//拿的个数遍历 
				for(int v=0;v<=12;v++)//最大价值遍历 
				{
					if(i==1&&j==1)//初始化 
					{
						if(k==0 || (k==1&&v>a[i][j]))//不拿也是一种,要拿并且可以拿也是一种 
							dp[i][j][k][v]=1;
						continue;
					}
					
					ll na=0,buna=0;//此处注意要赋初值 
					
					if(k!=0 && v>a[i][j])//可以拿
						// i-1是向上继承            j-1是向下继承 
						na=dp[i-1][j][k-1][a[i][j]]+dp[i][j-1][k-1][a[i][j]];
					buna=dp[i-1][j][k][v]+dp[i][j-1][k][v];
					
					dp[i][j][k][v]=( na%mod + buna%mod )%mod;
				}
	cout<<dp[n][m][K][12]<<endl;
	return 0;
}

 
