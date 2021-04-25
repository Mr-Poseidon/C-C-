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
    for(int i=0;i<=n-1;i++)
    {
        if(hh<tt && q[hh]==i-len)hh++;//出队
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//去掉末尾不符合的元素
        q[tt++]=i;//入队
        ans=max(ans,s[i+1]-s[q[hh]]);//维护最大值、然后求前缀和要r-(l-1)、所以s[i+1]中i要+1
    }
    cout<<ans;//输出答案
    return 0;
}




//--------方法二---------------------------------------------------------------
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1000010;

//单调队列维护的最值属性在队头
//调队列储存元素的下标
//维护元素下标的好处是，当元素是一个结构体元素时、可以不用重写比较符号 == 

int a[N];
int q[N],hh,tt;//维护单调队列单 
int n,len;

int main()
{
    scanf("%d%d",&n,&len);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    hh=0,tt=0;
    for(int i=0;i<n;i++)//维护最小值的单调队列
    {
        if(hh<tt && q[hh]<i-len)hh++;//出队
        while(hh<tt && a[q[tt-1]]>a[i])tt--;//维护尾部
        q[tt++]=i;//入队
        if(i-len+1>=0)printf("%d ",a[q[hh]]);//输出最小值
    }
    
    printf("\n");//换行
    
    hh=0,tt=0;
    for(int i=0;i<n;i++)//维护最大值的单调队列
    {
        if(hh<tt && q[hh]==i-len)hh++;//出队
        while(hh<tt && a[q[tt-1]]<a[i])tt--;//维护尾部
        q[tt++]=i;//入队
        if(i-len+1>=0)printf("%d ",a[q[hh]]);//输出最大值
    }
    
    return 0;
}
