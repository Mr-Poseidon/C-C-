#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1005;

//col[k]代表第k列是否已经使用
//dg[k]代表第k行正对角线是否已经使用
//udg[k]代表第k行反对角线是否已经使用
bool col[N],dg[2*N],udg[2*N];
int a[N];//存示例数据
int n,m;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        
        //初始化
        memset(col,false,sizeof(col));
        memset(dg,false,sizeof(dg));
        memset(udg,false,sizeof(udg));
        
        bool f=true;
        for(int i=0;i<m;i++)
        {
            int t=a[i];
            if(!col[t] && !dg[N-t+i] && !udg[t+i])//该皇后可以放置
                col[t]=dg[N-t+i]=udg[t+i]=true;//标记
            else //该皇后不能放置
            {
                f=false;
                break;//退出循环
            }
        }
        if(f)puts("YES");//输出结果
        else puts("NO");
    }
    return 0;
}
