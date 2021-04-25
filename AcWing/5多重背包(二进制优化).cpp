#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,f[2005];
struct Good
{
    int v,w;
};

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)//初始化 
		f[i]=0;
    
    vector<Good> goods;
    for(int i=0;i<n;i++)//对每一个物品进行二进制优化，存到迭代器中 
    {
       int v,w,s;
       cin>>v>>w>>s;
       for(int j=1;j<s;j*=2)//将s分成2的次方：1 2 4 8 16..... 
       {
           s-=j;
           goods.push_back({j*v,j*w});
       }
       if(s>0)goods.push_back({s*v,s*w});//若不够2的次方，则直接存入 
    }
    
    for(auto good:goods)//01背包 
    {
        for(int i=m;i>=good.v;i--)//避免处理小于good.v的部分 
            f[i]=max(f[i],f[i-good.v]+good.w);
    }
    cout<<f[m]<<endl;
    return 0;
}


/********************************分割线***********************************************/ 



#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=25000;

int v[N],w[N],cnt;//维护分解出来的物品价值和数量
int f[N];//维护背包
int n,m;

int main()
{
    cin>>n>>m;
    
    //将每个物品二进制分解
    while(n--)
    {
        int vi,wi,si;
        cin>>vi>>wi>>si;//输入
        
        //分解
        for(int i=1;i<=si;i<<=1)
        {
            v[cnt]=vi*i;
            w[cnt]=wi*i;
            si-=i;
            cnt++;
        }
        if(si>0)//注意多出来的部分
        {
            v[cnt]=vi*si;
            w[cnt]=wi*si;
            cnt++;
        }
    }
    
    for(int i=0;i<cnt;i++)//01背包
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    
    cout<<f[m]<<endl;//输出
    return 0;
    
}
