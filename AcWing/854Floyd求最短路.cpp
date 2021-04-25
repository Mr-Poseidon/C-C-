#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=210,INF=0x3f3f3f3f;

int d[N][N];//d[i][j]代表i到j的距离
int n,m,q;


void floyd()//floyd算法，时间复杂度O(N^3)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    for(int i=1;i<=n;i++)//邻接矩阵初始化
        for(int j=1;j<=n;j++)
            if(i==j)d[i][j]=0;//i==j代表一个点
            else d[i][j]=INF;
    
    while(m--)//输入边
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=min(d[a][b],c);//重边维护最小值
    }
    
    floyd();
    
    while(q--)//查询
    {
        int a,b;
        scanf("%d%d",&a,&b);
        
        //边权可能为负数，所以只要大于INF-200*20000即为不存在
        if(d[a][b]>INF/2)puts("impossible");//若不存在
        else printf("%d\n",d[a][b]);//存在
    }
    
    return 0;
}
