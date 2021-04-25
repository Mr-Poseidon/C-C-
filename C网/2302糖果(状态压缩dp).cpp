#include<iostream>
#include<cstring>
using namespace std;

int n,m,k;
int s[105],dp[(1<<20)+5];

int main()//O(n*(2^m)) 
{
	memset(dp,-1,sizeof(dp));
	memset(s,-1,sizeof(s));
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)//����ÿ���ǹ���״̬������� 
	{
		int sum=0;//���ϵ���״̬ 
		int t;
		for(int j=0;j<k;j++)
		{
			cin>>t;
			sum|=(1<<(t-1));//����Ԫ��״̬ 
		}
		s[i]=sum;//����״̬ 
		dp[sum]=1;//��� 
	}
	
	for(int i=0;i<n;i++)//����״̬ö�� 
	{
		for(int j=0;j<(1<<m);j++)//���м���״̬ö��
		{
			if(dp[j]==-1)continue;
			if(dp[j|s[i]]==-1)dp[j|s[i]]=dp[j]+dp[s[i]];
			else dp[j|s[i]]=min(dp[j|s[i]],dp[j]+dp[s[i]]);
		} 
	}
	//���ݲ�ͬ��Ҫ�󣬿��������ͬԪ��״̬�µĽ�� 
	cout<<dp[(1<<m)-1];//����ȫ��״̬�Ľ�� 
	return 0;
}
