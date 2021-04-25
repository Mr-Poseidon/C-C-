#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=15;

//若两个人同时走、那么他们的步数一定相等、但是位置不一定相等

int w[N][N];//w[i][j]维护点（i，j）的数值
int f[N*2][N][N];//f[k][i1][i2]维护k步、第一个人走的横向距离i1，第二个人走的横向距离i2，纵向距离即为k-i1和k-i2的最大值
int n,a,b,c;

int main()
{
    scanf("%d",&n);//输入矩阵宽
    
    while(scanf("%d%d%d",&a,&b,&c),a||b||c)w[a][b]=c;//输入矩阵值
    
    for(int k=2;k<=n+n;k++)//遍历步数
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;//得出两个点的纵向距离
                if(j1>=1 && j1<=n && j2>=1 && j2<=n)//若在合法范围内
                {
                    int t=w[i1][j1];
                    if(i1!=i2)t+=w[i2][j2];//若位置不相同、则两个值都加上、若位置相同、一个值只能取一次
                    
                    //选择转移的最大值
                    int &x=f[k][i1][i2];
                    x=max(x,f[k-1][i1-1][i2]);//向右、向下
                    x=max(x,f[k-1][i1][i2-1]);//向下、向右
                    x=max(x,f[k-1][i1-1][i2-1]);//向右、向右
                    x=max(x,f[k-1][i1][i2]);//向下、向下
                    
                    x+=t;//加上该点的数值
                }
            }
            
    printf("%d",f[n<<1][n][n]);//输出结果
    return 0;
        
}
