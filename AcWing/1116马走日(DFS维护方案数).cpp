#include<iostream>
#include<cstring>
using namespace std;

const int N=15;

bool vis[N][N];
int n,m,x,y;
int ans;

void dfs(int x,int y,int cnt)//���ѣ�x,y����Ŀǰ�����꣬cnt����Ŀǰ���������ѵ��ĵڼ�����
{
    if(cnt==n*m)//ȫ���ѵ�
    {
        ans++;
        return;
    }
    
    vis[x][y]=true;//���
    
    int d[8][2]={-1,-2,1,-2,-2,-1,-2,1,-1,2,1,2,2,-1,2,1};
    for(int i=0;i<8;i++)//�����˸�����
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//Խ��
        if(vis[nx][ny])continue;//���ʹ�
        
        dfs(nx,ny,cnt+1);
    }
    
    vis[x][y]=false;//ȡ�����
    return;
}

int main()
{
    int T;
    cin>>T;
    while(T--)//�����������
    {
        cin>>n>>m>>x>>y;//����
        
        //��ʼ������
        memset(vis,0,sizeof vis);
        ans=0;
        
        dfs(x,y,1);//����
        
        cout<<ans<<endl;//�����
    }
    return 0;
}
