/*
lower_bound()�����½�
upper_bound()�����Ͻ�
equal_range()�������� 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,len;
int a[1005],dp[1005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	len=1;
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		//����>=����ĩβ����,�����ǲ��½����У�������ͬ����������Ҫ= 
		if(a[i]>=dp[len]) 
			dp[++len]=a[i];//�������� 
		else
		{
			//�����������Ͻ��±�
			int t=upper_bound(dp+1,dp+1+len,a[i])-dp;
			dp[t]=a[i];
		}
	}
	cout<<len<<endl;
	return 0;
}
