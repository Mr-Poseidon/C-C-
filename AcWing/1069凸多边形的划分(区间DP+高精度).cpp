#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=55,INF=0x3f3f3f3f;
typedef vector<int> vec;
typedef long long LL;

//本题数值最大不超过30位：9+9+9+3=30，设置成35位

vec f[N][N];//f[i][j]维护i点到j点构成的凸多边形的所有划分情况的最小值
LL w[N];//w[i]维护i点的权值
int n;

vec add(vec a,vec b)//高精度+
{
    vec c;
    for(int i=0,t=0;i<a.size()||i<b.size()||t;i++)
    {
        if(i<a.size())t+=a[i];
        if(i<b.size())t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    return c;
}

vec mul(vec a,LL b)//高精度*
{
    vec c;
    LL t=0;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(c.size()>1 && c.back()==0)c.pop_back();
    return c;
}

int cmp(vec a,vec b)//高精度比较大小
{
    if(a.size()>b.size())return 1;
    else if(a.size()<b.size())return -1;
    
    for(int i=a.size()-1;i>=0;i--)
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return -1;
    
    return 0;
}

void print(vec a)//高精度输出
{
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    return;
}

int main()
{
    cin>>n;//输入
    for(int i=1;i<=n;i++)cin>>w[i];
    
    for(int i=0;i<=n;i++)//高精度初始化成0
        for(int j=0;j<=n;j++)
            f[i][j]=vec(1,0);
    
    for(int len=3;len<=n;len++)//枚举长度、凸多边形至少是一个三角形、由三个点构成
        for(int l=1;l+len-1<=n;l++)//枚举多边形的起点
        {
            int r=l+len-1;//多边形的终点
            f[l][r]=vec(35,9);//高精度初始化成最大值，即每一位都是9
            
            for(int k=l+1;k<r;k++)//枚举每一个可以划分的点
            {
                //f[l][r]=min(f[l][r],f[l][k]+f[k][r]+w[l]*w[k]*w[r]);//正常值的状态转移方程
                
                //大数状态转移方程
                vec t(1,1);//做乘法，初始化成1
                t=mul(t,w[l]);
                t=mul(t,w[k]);
                t=mul(t,w[r]);
                t=add(t,f[l][k]);
                t=add(t,f[k][r]);
                
                if(cmp(f[l][r],t)==1)//如果f[l][r]>t
                    f[l][r]=t;//取最小值
            }
        }
    print(f[1][n]);//输出结果
    return 0;
}

