#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=10005,null=0x3f3f3f3f;
typedef pair<int,int> PII;

int ms,n,m;
int h[N];

PII find(int x)//first代表位置，-1代表搜不到， second代表探索次数
{
    int step=0;
    for(int i=0;i<ms;i++)
    {
        int k=(x%ms+i*i)%ms;
        if(h[k]==null || h[k]==x)
            return {k,step+1};
        step++;
    }
    return {-1,step+1};
}

int main()
{
    cin>>ms>>n>>m;
    
    for(int i=ms;;i++)//找大于散列表大小的最小质数
    {
        bool f=true;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                f=false;
                break;
            }
        if(f)
        {
            ms=i;
            break;
        }
    }
    
    memset(h,0x3f,sizeof(h));//散列表初始化
    
    int x;
    while(n--)
    {
        cin>>x;
        PII p=find(x);//查找
        if(p.first!=-1)h[p.first]=x;//可以插入或存在
        else printf("%d cannot be inserted.\n",x);
    }
    
    int ans=0;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        PII p=find(x);//查找
        ans+=p.second;//加上探索的次数
    }
    printf("%.1f",ans*1.0/m);
    return 0;
}
