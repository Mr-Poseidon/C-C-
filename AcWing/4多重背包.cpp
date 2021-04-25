#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[105][105];
int vo,va,am;

int main()
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        map[0][i]=0;
    
    for(int i=1;i<=n;i++)//物品枚举 
    {
        cin>>vo>>va>>am;
        for(int j=0;j<=m;j++)//背包体积枚举          
            for(int k=0;k<=am;k++)//此处直接使用物品的可用数量 
                if(j>=k*vo)
                    map[i][j]=max(map[i][j],map[i-1][j-k*vo]+k*va);
    }
    cout<<map[n][m]<<endl;
    return 0;
}


/***************************分割线*****************************************/ 


#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int f[N][N];
int v[N],w[N],s[N];
int n,m;

int main()//完全背包解法
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>s[i];
    
    for(int i=1;i<=n;i++)//遍历物品
        for(int j=0;j<=m;j++)//遍历背包容量
            for(int k=0;k<=s[i] && k*v[i]<=j;k++)//遍历物品个数
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k] + w[i]*k);
    
    cout<<f[n][m]<<endl;
    return 0;
}
