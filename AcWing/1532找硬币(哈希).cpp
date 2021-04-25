#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=200003,INF=0x3f3f3f3f;

int h[N];
int a[N];
int n,m;

int find(int num)//开放寻址法哈希
{
    int k=(num%N+N)%N;

    while(h[k]!=INF && h[k]!=num)
    {
        k++;
        if(k==N)k=0;
    }

    return k;
}

int main()
{
    cin>>n>>m;//输入
    for(int i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);//排序

    memset(h,0x3f,sizeof h);//初始化哈希表
    for(int i=0;i<n;i++)h[find(a[i])]=a[i];//哈希

    for(int i=0;i<n;i++)//检索
    {
        int j=find(a[i]);
        int k=find(m-a[i]);

        if(h[k]==m-a[i] && j!=k)//j!=k表示两个数都存在、同样的数值也要出现两次
        {
            cout<<a[i]<<" "<<m-a[i];
            return 0;
        }
    }


    cout<<"No Solution";
    return 0;       
}
