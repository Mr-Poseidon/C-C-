#include<iostream>
#include<algorithm>
using namespace std;

long long int n,a[1005],dp[1005][1005];

int main()
{
	cin>>n;
	for(int i=1;i<=n+1;i++)
		cin>>a[i];

	//���ݳ�ʼ��
	for(int i=1;i<n;i++)//������߽� 
		for(int j=i+1;j<=n;j++)//�����ұ߽� 
			dp[i][j]=1e14; 
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	
	for(int len=2;len<=n;len++)//�����Сö��
		//�������ö�٣�ע�� i+len-1 Ϊ�����㣬��Ҫ������n�� 
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)//����ϵ����ö�� 
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
		}
	cout<<dp[1][n];
	return 0;
}
