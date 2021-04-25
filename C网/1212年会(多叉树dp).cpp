#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,l,k;
//dp[i][0��1] - 0��������1������
//parent[i] - ���i�ĸ��ڵ�
//map[i] - ��¼i���Ƿ��߹�
int dp[6005][2],parent[6005],map[6005];

void dfs(int root,int n)
{
	map[root]=1;
	for(int i=1;i<=n;i++)//Ѱ���ӽڵ�
	{
		if(parent[i]==root && map[i]==0)
		{
			dfs(i,n);
			dp[root][1]+=dp[i][0];//���� 
			//���������ӿ�����Ҳ���Բ���
			dp[root][0]+=max(dp[i][1],dp[i][0]); 
		}
	}
}

int main()
{
	memset(dp,0,sizeof(dp));
	memset(parent,0,sizeof(parent));
	memset(map,0,sizeof(map));
	
	cin>>n;//Ա���� 
	for(int i=1;i<=n;i++)//��ӦԱ���Ļ�Ծֵ 
		cin>>dp[i][1];
	while(cin>>l>>k && l!=0 && k!=0)//Ա����Ӧ�ĵ�ʦ 
		parent[l]=k;
		
	for(int i=1;i<=n;i++)//�ҳ����ڵ� 
	{
		if(parent[i]==i)
		{
			k=i;
			break;
		}
	}
	dfs(k,n);//���� 
	cout<<max(dp[k][0],dp[k][1]);//������ 
	return 0;
}

