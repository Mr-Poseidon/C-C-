#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
#define x first
#define y second

const int N=2510,M=6200*2+10;

int n,m,S,T;
int h[N],e[M],w[M],ne[M],idx;
int dis[N];
bool vis[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

//���Ż����djkstra
void dijkstra()
{
    memset(dis,0x3f,sizeof dis);//��ʼ������
    memset(vis,false,sizeof vis);//��ʼ���������
    priority_queue<PII,vector<PII>,greater<PII> > q;//���ȶ���
    
    //��㴦��
    dis[S]=0;
    q.push({0,S});
    
    while(!q.empty())
    {
        PII t=q.top();//����
        q.pop();
        
        int distance=t.x,u=t.y;
        if(vis[u])continue;
        vis[u]=true;
        
        for(int i=h[u];~i;i=ne[i])//�����ڽӵ�
        {
            int j=e[i];
            if(distance+w[i]<dis[j])//���ڸ��̾���
            {
                dis[j]=distance+w[i];//����
                q.push({dis[j],j});//���
            }
        }
    }
    
}

int main()
{
    cin>>n>>m>>S>>T;
    
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    dijkstra();
    
    cout<<dis[T];
    return 0;
}
