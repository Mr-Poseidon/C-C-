#include<cstdio>
using namespace std;

//本题全排列中不包含重复的元素

const int N=10;

int path[N];
bool use[N];
int n;


void dfs(int k)//深搜
{
    if(k==n)//输出
    {
        for(int i=0;i<n;i++)printf("%d ",path[i]);
        puts("");
        return;
    }
    
    for(int i=1;i<=n;i++)//遍历可能的情况
    {
        if(!use[i])//i这个数没有用过
        {
            use[i]=true;
            path[k]=i;
            dfs(k+1);
            use[i]=false;
        }
    }
    return;
}

int main()
{
    
    scanf("%d",&n);
    
    dfs(0);
    
    return 0;
}

