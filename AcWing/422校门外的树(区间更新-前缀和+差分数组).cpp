#include<iostream>
using namespace std;

const int N=10010;

int f[N];//维护差分数组，前缀和
int n,m;

int main()
{
    cin>>n>>m;
    
    //因为维护前缀和、所有坐标点右移一位，1代表0点
    f[0+1]=1;//初始化
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        
        //更新
        f[a+1]--;//起点自减
        f[b+1+1]++;//终点的后一位自加
    }
    
    int ans=0;//记录答案
    for(int i=1;i<=n+1;i++)
    {
        f[i]+=f[i-1];//求一遍前缀和
        if(f[i]>0)ans++;//结果大于0即存在树
    }
    
    cout<<ans;//输出结果
    return 0;
}
