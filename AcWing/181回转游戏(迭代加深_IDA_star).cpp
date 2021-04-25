#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=25;

int g[N];//维护图
//维护8个操作所对应的值的下标
int operate[8][8]={
    {0,2,6,11,15,20,22},
    {1,3,8,12,17,21,23},
    {10,9,8,7,6,5,4},
    {19,18,17,16,15,14,13},
    {23,21,17,12,8,3,1},
    {22,20,15,11,6,2,0},
    {13,14,15,16,17,18,19},
    {4,5,6,7,8,9,10}
};
int center[8]={6,7,8,11,12,15,16,17};//维护中间圈内八个数值所对应的下标
int opposite[8]={5,4,7,6,1,0,3,2};//每个操作的相反操作
int path[100];//维护操作步骤的序列

//由于每进行一次操作、最多增加某个数中的一个，所以、8-出现最多的数的次数，就是还需要的最少的操作步骤
int f()//估值函数
{
    int sum[4]={0};//维护每个数出现的次数
    for(int i=0;i<8;i++)sum[g[center[i]]]++;
    
    int ans=0;//ans代表1-3这三个数中出现最多次的数的个数
    for(int i=1;i<=3;i++)ans=max(ans,sum[i]);//求出最大值
    return 8-ans;//返回还需要的最少的操作次数
}

void operation(int u)//操作
{
    //对于每一个操作、都是把第一个数放到最后面、其他数前移
    int t=g[operate[u][0]];
    for(int i=0;i<6;i++)g[operate[u][i]]=g[operate[u][i+1]];
    g[operate[u][6]]=t;
}

bool dfs(int depth,int max_depth,int pre)//depth为目前的深度，max_depth为可到达的最大深度，pre代表前一个操作的序号
{
    if(depth+f()>max_depth)return false;//A*,可行性剪枝
    if(f()==0)return true;//搜索完成
    
    for(int i=0;i<8;i++)//遍历八个操作，优化搜索顺序，保证最小字典序
    {
        if(opposite[i]==pre)continue;//剪枝、不做反向操作、排除等效冗余
        
        operation(i);//操作
        path[depth]=i;//记录操作方案
        if(dfs(depth+1,max_depth,i))return true;//深搜
        operation(opposite[i]);//恢复操作
    }
    return false;
}
int main()
{
    while(cin>>g[0] && g[0])
    {
        for(int i=1;i<24;i++)cin>>g[i];//输入
        
        int depth=0;//深度
        while(!dfs(0,depth,-1))depth++;//迭代加深
        
        if(depth==0)cout<<"No moves needed";
        else
        {
            for(int i=0;i<depth;i++)cout<<(char)(path[i]+'A');//输出路径
        }
        cout<<endl;
        cout<<g[center[0]]<<endl;//输出八个格子内的数
    }
    return 0;
}
