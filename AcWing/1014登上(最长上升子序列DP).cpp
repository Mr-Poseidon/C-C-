#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N];
int f[N],g[N];
int n;

int main()
{
    scanf("%d",&n);//输入数据
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++)//计算从前往后的最长上升子序列
    {
        f[i]=1;//本身的长度为1
        for(int j=1;j<i;j++)//遍历前面的值
            if(a[j]<a[i])//若前面的值比现在的小、说明现在的值能放在后面
                f[i]=max(f[i],f[j]+1);//状态转移方程
    }
    
    for(int i=n;i;i--)//从后往前
    {
        g[i]=1;
        for(int j=n;j>i;j--)
            if(a[j]<a[i])
                g[i]=max(g[i],g[j]+1);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)//遍历所有的点、看哪一个点作为走到的最高的景点比较好
        ans=max(ans,f[i]+g[i]-1);//最高点被计算两次、所以-1
    
    printf("%d",ans);//输出答案
    return 0;
}
