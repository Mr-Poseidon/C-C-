#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=300005;

int s[N];//维护前缀和 
int n,len;
int q[N],hh,tt;//维护单调队列 

int main()
{
    scanf("%d%d",&n,&len);
    for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];//输入并维护前缀和 
    
    int ans=-0x3f3f3f3f;//初始化 
    hh=0,tt=0;
    for(int i=0;i<n;i++)
    {
        if(hh<tt && q[hh]==i-len)hh++;//出队 
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//维护末尾 
        q[tt++]=i;//入队 
        ans=max(ans,s[i+1]-s[q[hh]]);//因为前缀和是r-(l-1),所以这边s[i+1],然后减去前面区间的最小值 
    }
    cout<<ans;
    return 0;
}






//-----方法二--------------------------------------------------------------------------
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=3000005;

//维护长度小于等于m的连续子序列的最大值，就是维护长度为m的区间的最小值、然后用 s[i]-最小值 就是最大值

int s[N];//维护前缀和
int n,len;
int q[N],hh,tt;//维护单调队列

int main()
{
    scanf("%d%d",&n,&len);//输入
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];//维护前缀和
    }
    
    int ans=-0x3f3f3f3f;//初始化
    hh=0,tt=0;
    q[tt++]=0;//s[0]入队
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]==i-len-1)hh++;//出队、因为前缀和0没有用、所以要-1
        ans=max(ans,s[i]-s[q[hh]]);//维护最大值、然后求前缀和要r-(l-1),所以要先维护再入队
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//去掉末尾不符合的元素
        q[tt++]=i;//入队
        
    }
    cout<<ans;//输出答案
    return 0;
}
