#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=50010;

int f[N],w[N];//f[i]维护前i个数的最小值，w[i]维护第i点的权值
int n,T;
int q[N],hh,tt;//维护单调队列

bool check(int len)//判断空的长度为len是否可以实现
{
    hh=tt=0;
    q[tt++]=0;
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-len-1)hh++;//可以空的长度为len，所以可以取到前面那一个数，所以-1
        f[i]=f[q[hh]]+w[i];//实现结果累加
        while(hh<tt && f[q[tt-1]]>f[i])tt--;//维护队列最小值
        q[tt++]=i;
    }
    
    for(int i=n-len;i<=n;i++)//判断是否存在<=T的值、存在说明这个长度可以实现
        if(f[i]<=T)
            return true;
    return false;
}
int main()
{
    cin>>n>>T;
    for(int i=1;i<=n;i++)cin>>w[i];
    
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;//本题求长度至少有多少、即求最小值、成立就变小
        else l=mid+1;//否则扩大
    }
    
    cout<<l<<endl;//输出结果，l、r都可以
    return 0;
    
}
