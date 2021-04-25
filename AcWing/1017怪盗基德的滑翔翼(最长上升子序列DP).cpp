#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=110;

int a[N];
int f[N],g[N];//f[]维护从前往后的最长子序列值，g[]维护从后往前的最长子序列值
int n;


int main()
{
    int T;
    scanf("%d",&T);//输入数据组数
    
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);//输入数据
        
        int ans=0;//结果
        for(int i=1;i<=n;i++)//从前往后
        {
            f[i]=1;//最少长度为1
            for(int j=1;j<i;j++)//遍历前面的值
                if(a[j]<a[i])//若比当前小，该数可以接在后面
                    f[i]=max(f[i],f[j]+1);//状态转移
            
            ans=max(ans,f[i]);//求最大值
        }
        
        for(int i=n;i;i--)//从后往前
        {
            g[i]=1;
            for(int j=n;j>i;j--)
                if(a[j]<a[i])
                    g[i]=max(g[i],g[j]+1);
            
            ans=max(ans,g[i]);
        }
        
        printf("%d\n",ans);//输出结果
    }
    return 0;
}
