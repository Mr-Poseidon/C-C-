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
    
    memset(dis,0x3f,sizeof dis);//�����ʼ��
    
    //������ÿ���㵽����ľ����ʼ����0�����ÿ���㱾��ľ�������⣬�����㵽����ľ�����Ȼ��ȷ
    for(int i=1;i<=n;i++)dis[i][i]=0;//���������ʼ��Ϊ0
    for(int i=0;i<m;i++)//����ͼ
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=dis[b][a]=c;
    }
    
    //floyd�㷨
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            
    //�������еĵ㣬ѡ���������ĵ�ľ��뼴Ϊ���
    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,dis[1][i]);
    
    if(ans==0x3f3f3f3f)puts("-1");//�����޷�����ĵ�
    else cout<<ans<<endl;
    
    return 0;
}
