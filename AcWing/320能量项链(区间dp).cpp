#include<iostream>
#include<algorithm>
#define maxn 202
using namespace std;

int n,a[maxn],dp[maxn][maxn]={0},ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];//�ϻ�����
    }
       
    
    for(int len=2;len<=n;len++)//�ϲ������Сö��
    {
        for(int i=1;i+len-1<2*n;i++)//�������ö��
        {
            int j=i+len-1;//�����յ�
            for(int k=i;k<j;k++)//���仮��ö��:������ֳ� i~k �� k+1~j ������������
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);//״̬ת�ƹ�ʽ 
        }
    }
    
    for(int i=1;i<=n;i++)//ö�����п��ܵĽ��
        ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
}
