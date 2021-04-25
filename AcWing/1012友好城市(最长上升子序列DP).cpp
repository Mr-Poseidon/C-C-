#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=5010;
typedef pair<int,int> PII;


//本题以其中一个岸作为参考点排序、求另外一个岸的 最长上升子序列 即为答案

PII q[N];
int f[N];
int n;

int main()
{
    scanf("%d",&n);//输入数据
    for(int i=1;i<=n;i++)scanf("%d%d",&q[i].first,&q[i].second);
    
    sort(q+1,q+1+n);//排序
    
    int ans=0;
    
    for(int i=1;i<=n;i++)//从前往后 求 最长上升子序列
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(q[j].second<q[i].second)
                f[i]=max(f[i],f[j]+1);
        ans=max(ans,f[i]);//记录最大值
    }
    
    printf("%d",ans);//输出结果
    return 0;
}
