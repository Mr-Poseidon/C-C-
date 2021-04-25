#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N];//维护序列
int f[N];//维护最长子序列的最大值
int n;

int main()
{
    scanf("%d",&n);//输入数据
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=a[i];//本身也算一个序列、最大值为本身
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+a[i]);//状态转移方程
        ans=max(ans,f[i]);//记录最大值
    }
    
    printf("%d",ans);//输出结果
    return 0;
}
