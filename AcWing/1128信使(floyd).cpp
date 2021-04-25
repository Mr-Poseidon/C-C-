#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=105,M=205;

int n,m;
int dis[N][N];

int main()
{
    cin>>n>>m;
    
    memset(dis,0x3f,sizeof dis);//距离初始化
    
    //若不对每个点到自身的距离初始化成0，则除每个点本身的距离错误外，其他点到本点的距离仍然正确
    for(int i=1;i<=n;i++)dis[i][i]=0;//自身点距离初始化为0
    for(int i=0;i<m;i++)//输入图
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=dis[b][a]=c;
    }
    
    //floyd算法
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            
    //遍历所有的点，选出距离最大的点的距离即为结果
    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,dis[1][i]);
    
    if(ans==0x3f3f3f3f)puts("-1");//存在无法到达的点
    else cout<<ans<<endl;
    
    return 0;
}
