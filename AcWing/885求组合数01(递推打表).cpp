#include<iostream>
#include<algorithm>
using namespace std;

const int N=2010,mod=1e9+7;

int c[N][N];//c[][]代表c(i,j)的情况


void init()//初始化矩阵表
{
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            if(!j)c[i][j]=1;//当不选的时候有一种情况
            //                    包含      不包含
            //根据递归公式c(i,j)=c(i-1,j)+c(i-1,j-1)
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}

int main()
{
    init();
    
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }
    return 0;
}
