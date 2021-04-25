#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int n,m;
char a[N],b[N];//维护两个字符串
int f[N][N];//f[i][j]表示 a的前i个字符串 和 b的前j个字符串 的最长公共子序列

int main()
{
    //输入，由于存在i-1,j-1,所以字符串下标由1开始
    cin>>n>>m>>a+1>>b+1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            //f[i][j]包含四种情况：（选ai，不选ai）*(选bj，不选bj)
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
        
    cout<<f[n][m];//输出
    return 0;
}
