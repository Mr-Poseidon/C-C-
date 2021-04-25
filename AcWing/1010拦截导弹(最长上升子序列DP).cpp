#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N],n;//维护序列
int f[N];//维护最长不下降子序列最大值
int sd[N];//维护最长不下降子序列的情况数
int cnt;//维护序列数量

int main()
{
    int t;
    while(cin>>t)a[n++]=t;
    
    int ans=0;//维护最大值 
    for(int i=0;i<n;i++)//求最长不下降子序列
    {
        f[i]=1;
        for(int j=0;j<i;j++)
            if(a[j]>=a[i])
                f[i]=max(f[i],f[j]+1);
                
        ans=max(ans,f[i]);//求最大值 
    }
    
    for(int i=0;i<n;i++)//求序列的数量
    {
        int k=0;//从头开始
        while(k<cnt && sd[k]<a[i])k++;//这个序列无法插入
        if(k==cnt)sd[cnt++]=a[i];//开一个新的序列
        else sd[k]=a[i];//插入一个旧的序列
    }
    
    printf("%d\n%d",ans,cnt);
    return 0;
}
