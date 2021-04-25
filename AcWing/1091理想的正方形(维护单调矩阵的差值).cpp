#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int g[N][N];//存放初始矩阵
int gmax[N][N],gmin[N][N];//gmax维护最大值的矩阵，gmin维护最小值的矩阵
int n,m,k;
int q[N],hh,tt;//维护单调队列


void get_max(int a[],int b[],int tot)//维护最大值的单调队列
{
    hh=tt=0;
    for(int i=1;i<=tot;i++)
    {
        if(hh<tt && q[hh]<=i-k)hh++;
        while(hh<tt && a[q[tt-1]]<a[i])tt--;
        q[tt++]=i;
        b[i]=a[q[hh]];
    }
}

void get_min(int a[],int b[],int tot)//维护最小值的单调队列
{
    hh=tt=0;
    for(int i=1;i<=tot;i++)
    {
        if(hh<tt && q[hh]<=i-k)hh++;
        while(hh<tt && a[q[tt-1]]>a[i])tt--;
        q[tt++]=i;
        b[i]=a[q[hh]];
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);//输入
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
            
    for(int i=1;i<=n;i++)//遍历每一行
    {
        get_min(g[i],gmin[i],m);//维护每一行的最小值
        get_max(g[i],gmax[i],m);//维护每一行的最大值
    }
    
    int ans=0x3f3f3f3f;//初始化答案
    int a[N],b[N],c[N];//a用来存放临时的列，b用来存列的最小值，c用来存列最大值
    for(int i=k;i<=m;i++)//遍历列，从k列开始
    {
        for(int j=1;j<=n;j++)a[j]=gmin[j][i];//列处理到临时数组
        get_min(a,b,n);//维护列的最小值
        
        for(int j=1;j<=n;j++)a[j]=gmax[j][i];//列处理到临时数组
        get_max(a,c,n);//维护列的最大值
        
        for(int j=k;j<=n;j++)ans=min(ans,c[j]-b[j]);//从k开始，维护最小的差值
    }
    
    printf("%d\n",ans);//输出结果
    return 0;
}
