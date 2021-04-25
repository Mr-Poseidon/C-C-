#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=110;

int a[N];//a[]维护子序列
int f[N],g[N];//f[]维护从前往后的最长上升子序列的值，g[]维护从后往前
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);//输入
    
    for(int i=1;i<=n;i++)//从前往后
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
    }
    
    for(int i=n;i;i--)//从后往前
    {
        g[i]=1;
        for(int j=n;j>i;j--)
            if(a[j]<a[i])
                g[i]=max(g[i],g[j]+1);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)//计算最大值
        ans=max(ans,f[i]+g[i]-1);
    
    printf("%d",n-ans);//输出最小值
    return 0;
}
