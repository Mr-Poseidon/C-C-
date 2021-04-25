#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N=25;

char mp[N][N];//ά��ͼ
int vis[N][N];//�ж��Ƿ��߹�
int n,m;

int dfs(int x,int y)//����
{
    int ans=0;
    if(x>0 && x<=n && y>0 && y<=m && mp[x][y]=='.' && vis[x][y]==0)//��������
    {
        vis[x][y]=1;
        ans++;//��¼����
        
        //�ĸ���������ߵ�������
        ans+=dfs(x+1,y);
        ans+=dfs(x,y+1);
        ans+=dfs(x-1,y);
        ans+=dfs(x,y-1);
    }
    return ans;//���ؽ��
}

int main()
{
    while(cin>>m>>n && n && m)//��������
    {
        memset(vis,0,sizeof vis);//��ʼ�����
        
        int x,y;
        for(int i=1;i<=n;i++)//����ͼ
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                
                if(mp[i][j]=='@')//������
                {
                    x=i;
                    y=j;
                    mp[x][y]='.';
                }
            }
        
        cout<<dfs(x,y)<<endl;//���ѣ�������
    }
    return 0;
}
