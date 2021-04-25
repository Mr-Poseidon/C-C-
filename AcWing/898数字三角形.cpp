#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=510;

int a[N][N];//维护三角形
int f[N][N];//维护每一个点作为一个三角形顶点的最大值
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//输入三角形
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
            
    for(int i=n;i>=1;i--)//从底部开始向上转移
        for(int j=1;j<=i;j++)//遍历该层的每一个数
            f[i][j]=max(f[i+1][j]+a[i][j],f[i+1][j+1]+a[i][j]);//从左下上来 或者 从右下上来
    
    cout<<f[1][1];//输出结果
    return 0;
}
