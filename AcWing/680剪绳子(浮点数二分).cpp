#include<iostream>
#include<cstdio>
using namespace std;

const int N=100010;

int w[N];
int n,m;

bool check(double len)
{
    int cnt=0;//计算能够剪出的条数
    for(int i=0;i<n;i++)
        cnt+=w[i]/len;
    
    return cnt>=m;//能够剪出的条数 大于 要求的条数，说明符合条件，可以继续加长
}

int main()
{
    cin>>n>>m;//输入
    for(int i=0;i<n;i++)cin>>w[i];
    
    double l=0,r=1e9;
    while(r-l>1e-4)//浮点数二分
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;//如果符合，就加长
        else r=mid;//否则就变短
    }
    
    printf("%.2lf",r);//输出结果
    return 0;
}
