#include<iostream>
using namespace std;

typedef long long int ll;

int n,m,K;
int a[52][52]={0};//��ÿ����ļ�ֵ 
ll dp[52][52][13][13]={0};
int mod=1e9+7;

int main()
{
	cin>>n>>m>>K;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	
	for(int i=1;i<=n;i++)//�б��� 
		for(int j=1;j<=m;j++)//�б��� 
			for(int k=0;k<=K;k++)//�õĸ������� 
				for(int v=0;v<=12;v++)//����ֵ���� 
				{
					if(i==1&&j==1)//��ʼ�� 
					{
						if(k==0 || (k==1&&v>a[i][j]))//����Ҳ��һ��,Ҫ�ò��ҿ�����Ҳ��һ�� 
							dp[i][j][k][v]=1;
						continue;
					}
					
					ll na=0,buna=0;//�˴�ע��Ҫ����ֵ 
					
					if(k!=0 && v>a[i][j])//������
						// i-1�����ϼ̳�            j-1�����¼̳� 
						na=dp[i-1][j][k-1][a[i][j]]+dp[i][j-1][k-1][a[i][j]];
					buna=dp[i-1][j][k][v]+dp[i][j-1][k][v];
					
					dp[i][j][k][v]=( na%mod + buna%mod )%mod;
				}
	cout<<dp[n][m][K][12]<<endl;
	return 0;
}

 
