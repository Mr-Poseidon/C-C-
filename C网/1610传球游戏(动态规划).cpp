#include<iostream>
using namespace std;

int dp[32][32];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)dp[0][i]=0;//��ʼ�� 
	dp[0][0]=1;
	
	for(int i=1;i<=m;i++)//���ݴ������� 
		for(int j=0;j<n;j++)//n��ͬѧ����Ĵ���ֻ��n-1��n+1���� 
			dp[i][j]=dp[i-1][(j+n-1)%n]+dp[i-1][(j+n+1)%n];
	cout<<dp[m][0];
	return 0;
}
