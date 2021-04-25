#include<iostream>
#include<cstring>
using namespace std;

const int N=10003,null=0x3f3f3f3f;
int h[N];

int n,m;

int find(int x)//只具有正增量的二次探测法
{
    for(int i=0;i<m;i++)
    {
        int k=(x%m+i*i)%m;//正增量是指 只加上i^2 
        if(h[k]==null || h[k]==x)
            return k;
    }
    return -1;//不存在或者无法插入
}

int main()
{
    memset(h,0x3f,sizeof(h));//散列表初始化
    
    cin>>m>>n;
    //获取大于散列表大小的最小质数
    for(int i=m;;i++)
    {
        bool f=true;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
            {
                f=false;
                break;
            }
        if(f)
        {
            m=i;//质数赋值
            break;
        }
    }
    
    int x;
    while(n--)
    {
        cin>>x;
        int k=find(x);//哈希
        if(k!=-1)//是否存在
        {
            cout<<k<<' ';
            h[k]=x;
        }
        else cout<<"- ";
    }
    return 0;  
}
