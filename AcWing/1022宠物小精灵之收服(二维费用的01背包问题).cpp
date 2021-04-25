#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010,M=510;

int f[N][M];//f[i][j]维护 精灵球数量为i，体力值为j时，可捕捉的精灵的最大数量
int n,m,k;

int main()
{
    cin>>n>>m>>k;
    
    while(k--)
    {
        int v1,v2;
        cin>>v1>>v2;//输入两个价值
        
        for(int i=n;i>=v1;i--)//遍历精灵球数量
            for(int j=m-1;j>=v2;j--)//变换思维：体力值不能等于0、就预留出1点体力值、从m-1开始
                f[i][j]=max(f[i][j],f[i-v1][j-v2]+1);
    }
    
    int c=f[n][m-1],r;//可捕捉的精灵最大值 f[n][m-1]中的 m-1 也是预留出1点体力值
    for(int i=0;i<=m-1;i++)//从最小值开始遍历花费的体力值，当f[n][i]==c时，代表体力值花费的最小值为i，剩下的体力值即为最大
        if(f[n][i]==c)
        {
            r=i;
            break;
        }
    
    cout<<c<<" "<<m-r;//输出最大可捕捉的精灵数量、和 剩余体力 的最大值
    return 0;
}
