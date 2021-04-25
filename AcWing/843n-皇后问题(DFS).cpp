#include<cstdio>
#include<iostream>
using namespace std;

const int N=10;

//dg-diagonal对角线
//col[k]代表k第k列有被使用过
//dg[k]代表k第k条正对角线有被使用过
//udg[k]代表k第k条反对角线有被使用过
bool col[N],dg[2*N],udg[2*N];
char mp[N][N];
int n;



void dfs(int k)//深搜，k代表第几行
{
    if(k==n)//超出搜索层数
    {
        for(int i=0;i<n;i++)puts(mp[i]);
        puts("");
        return;
    }
    
    /*
        正对角线: y = x + b 即 b = y - x, b可能为负数,所以需要加个N保证为正数
        反对角线：y = x - b 即 b = y + x
    */
    for(int i=0;i<n;i++)//i代表第几列
    {
        if(!col[i] && !dg[i-k+N] && !udg[i+k])//如果该列，并且该列所在的正对角线和反对角线都没用过，继续深搜
        {
            col[i]=dg[i-k+N]=udg[i+k]=true;//改变状态
            mp[k][i]='Q';
            dfs(k+1);
            mp[k][i]='.';
            col[i]=dg[i-k+N]=udg[i+k]=false;//恢复状态
        }
    }
    return;
}


int main()
{
    scanf("%d",&n);
    
    //初始化图
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[i][j]='.';
    
    dfs(0);
    
    return 0;
}

