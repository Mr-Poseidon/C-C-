#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110;

int n;
int path[N];//维护任意可能的序列 

bool dfs(int u,int depth)//迭代加深搜索
{
    if(path[u-1]==n)return true;//前一个数是我们想要的结果
    if(u==depth)return false;//超越指定深度
    
    bool use[N]={false};//用于记录用过的数、避免重复搜索
    
    //枚举每个可能的数
    for(int i=u-1;i>=0;i--)//优化搜索顺序、优先搜索最大值、所以从后往前枚举
        for(int j=i;j>=0;j--)
        {
            int v=path[i]+path[j];
            if(v>n || v<path[u-1] || use[v])continue;//越界、或者用过、跳过
            
            use[v]=true;//标记
            path[u]=v;//记录
            if(dfs(u+1,depth))return true;//继续搜索
        }
    return false;
}
int main()
{
    
    while(cin>>n && n)//多组测试数据
    {
        path[0]=1;//第一个数为1
        int depth=1;//深度为1
        
        while(!dfs(1,depth))depth++;//迭代加深搜索
        
        for(int i=0;i<depth;i++)cout<<path[i]<<" ";//输出
        cout<<endl;
    }
    return 0;
}
