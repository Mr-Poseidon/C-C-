#include<iostream>
#include<algorithm>
#define maxn 202
using namespace std;

int a[maxn],dp[maxn][maxn]={0},n,ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//�ϻ����� 
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int len=2;len<=n;len++)//�����Сö�� 
    {
        for(int i=1;i+len-1<2*n;i++)//�������ö�� 
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)//�������黮��ö�� 
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);//״̬ת�Ʒ��� 
            }
        }
    }
    for(int i=1;i<=n;i++)//�������������ֵö�� 
        ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
    
}
