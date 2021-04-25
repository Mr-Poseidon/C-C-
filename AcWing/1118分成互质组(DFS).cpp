#include<iostream>
#include<algorithm>
using namespace std;

const int N=15;

int a[N];//维护每一个数
int g[N][N];//g[i][j]维护第i组的第j个数
int si[N];//si[i]维护第i组中数的个数
int n,cnt,ans;//cnt维护目前一共建立了多少组数，ans维护目前完全分配完的最少的组的数量

int gcd(int a,int b)//求最大公约数
{
    return b==0?a:gcd(b,a%b);
}

bool check(int k,int num)//判断num这个数是否和第k组数完全互质
{
    for(int i=0;i<si[k];i++)
        if(gcd(num,g[k][i])!=1)
            return false;
    return true;
}

void dfs(int kk)
{
    if(cnt>=ans)return;//剪枝，当分组的数量大于当前的答案、就一定不会是最小值
    if(kk==n)//搜完最后一个数
    {
        ans=min(ans,cnt);//维护最小值
        return;
    }
    
    for(int i=0;i<cnt;i++)//遍历每一组，看能不能存放在已创建的组中
        {
            if(check(i,a[kk]))//如果这个数和这组数完全互质
            {
                g[i][si[i]++]=a[kk];//将这个数放在这组数中
                dfs(kk+1);//搜索下一个数
                si[i]--;//第i组数的个数-1，即取出这个数
            }
        }
        
    //建立一个新的组
    g[cnt][si[cnt]]=a[kk];//新组存放这个数
    si[cnt]++;//新组数的个数+1
    cnt++;//组数+1
    
    dfs(kk+1);//搜索下一个数
    
    cnt--;//组数-1
    si[cnt]--;//最后一组的数的个数-1
    
    return;
}
int main()
{
    cin>>n;//输入
    for(int i=0;i<n;i++)cin>>a[i];
    
    cnt=0;//初始化组的数量
    ans=n;//初始化结果，最多分成n组
    
    dfs(0);//从第0个数开始搜索
    
    cout<<ans;//输出答案
    return 0;
}
