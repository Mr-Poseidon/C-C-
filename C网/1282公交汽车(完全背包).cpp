/*
��ȫ���� 
*/ 

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[11],dp[12][102];

int main()
{
	for(int i=1;i<=10;i++)
		cin>>a[i];
	cin>>n;
	
	//ע��˴��ͱ������в�ͬ 
	for(int i=0;i<=n;i++)//���ݳ�ʼ��
		dp[0][i]=i*a[1];
	
	for(int i=1;i<=10;i++)//��Ʒ����-��Ʊ���� 
	{
		for(int j=0;j<=n;j++)//������������-���̱��� 
		{
			dp[i][j]=dp[i-1][j];
			int acount=j/i;
			for(int k=1;k<=acount;k++)//��Ʊ�������� 
				//״̬ת�Ʒ��� 
				dp[i][j]=min( dp[i][j] , dp[i-1][j-i*k] + a[i]*k );
		}
	}
	cout<<dp[10][n]<<endl;
	return 0;
} 
