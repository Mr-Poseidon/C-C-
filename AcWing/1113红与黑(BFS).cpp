#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N=25;
typedef pair<int,int> PII;

char mp[N][N];//ά��ͼ
int vis[N][N];//�ж��Ƿ��߹�
int n,m;

int dir[4][2]={1,0,0,1,-1,0,0,-1};//�ĸ�����

int main()
{
    while(cin>>m>>n && n && m)//��������
    {
        queue<PII> q;//����
        int ans=0;//��
        memset(vis,0,sizeof vis);//��ʼ�����
        
        for(int i=1;i<=n;i++)//����ͼ
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                
                if(mp[i][j]=='@')//�����㡢���
                {
                    q.push({i,j});
                    ans++;
                }
            }
                
        
        while(!q.empty())//����
        {
            PII p=q.front();//����
            q.pop();
            
            for(int i=0;i<4;i++)//�����ĸ�����
            {
                int x=p.first+dir[i][0];
                int y=p.second+dir[i][1];
                
                if(x>0 && x<=n && y>0 && y<=m && vis[x][y]==0 && mp[x][y]=='.')//��������
                {
                    vis[x][y]=1;//���
                    ans++;//�����ߵ�������+1
                    q.push({x,y});//���
                }
            }
        }
        
        cout<<ans<<endl;//������
    }
    return 0;
}
