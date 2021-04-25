#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=3010;

int a[N],b[N];//维护a,b两个序列
int f[N];//维护以b[i]结尾的 最长公共上升子序列 的值
int n;


int main()
{
    scanf("%d",&n);//输入 
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    
    for(int i=1;i<=n;i++)
    {
        int maxv=0;//维护前缀 最长公共上升子序列 的最大值
        for(int j=1;j<=n;j++)
        {
            //此处因为a[i]==b[j]是才会出现值贡献+1
            //b[j]<b[i] 表示 b[i] 可以放在 b[j] 后面，构成新的公共子序列
            //所以b[j]<b[i] 等价于 b[j]<a[i], 此处是一个优化点
            //注意：本题类似背包,更新、比较的值都是f[j]
            
            if(b[j]<a[i])maxv=max(maxv,f[j]);//判断最大值能否更新，能的话就更新
            if(b[j]==a[i])f[j]=maxv+1;//b[j]==a[i]时，贡献度+1，值更新
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);//查找最大值
    
    printf("%d",ans);//输出结果
    return 0;
}
