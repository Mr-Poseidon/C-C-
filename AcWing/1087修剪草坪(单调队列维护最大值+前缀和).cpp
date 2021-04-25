#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+10;

ll f[N],s[N];//f[i]维护前i头牛的最优方案，s[i]维护前i头牛的效率前缀和
int n,m;
int q[N],hh,tt;//维护单调队列

/*
    选择第i头牛的情况:f[i]=f[i-j-1]+s[i]-s[i-j],1<=j<=m
    因为j是变量，等式变形为：f[i]=(f[i-j-1]-s[i-j]) + s[i],将 f[i-j-1]-s[i-j] 看成一整个部分
    为了方便，将 f[i-j-1]-s[i-j] 包装成一个函数g(i-j) = f[i-j-1]-s[i-j] ，将i-j看成一个整体，即得g(i)=f[i-1]-s[i];
    不选的情况：f[i]=f[i-1]
    
    因为是求最大值，所以 f[i] = max( f[i-1] , g(q[hh])+s[i] )
*/

ll g(int i)//将 f[i-j-1]-s[i-j] 包装成一个函数g(i-j) = f[i-j-1]-s[i-j] 
{
    return f[i-1]-s[i];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)//输入数据
    {
        cin>>s[i];
        s[i]+=s[i-1];//维护前缀和
    }
    
    hh=tt=0;
    q[tt++]=0;//第0个也算进去、方便状态转移
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-m)hh++;//出队
        f[i]=max(f[i-1],g(q[hh])+s[i]);//维护最大值
        while(hh<tt && g(q[tt-1])<g(i))tt--;//维护 f[i-j-1]-s[i-j] 的最大值
        q[tt++]=i;//入队
    }
    
    cout<<f[n];//输出结果
    return 0;
}

