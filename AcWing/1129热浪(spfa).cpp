#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=2510,M=6200*2+10;//����ͼ����*2

int n,m,S,T;
int h[N],e[M],w[M],ne[M],idx;
int dis[N];
int vis[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa()
{
    memset(dis,0x3f,sizeof dis);//��ʼ������
    memset(vis,0,sizeof vis);//��ʼ���������
    queue<int> q;//����
    
    dis[S]=0;
    q.push(S);
    vis[S]=true;
    
    while(!q.empty())
    {
        int t=q.front();//����
        q.pop();
        vis[t]=false;//ȡ�����
        
        for(int i=h[t];~i;i=ne[i])//���������ڽӵĵ�
        {
            int j=e[i];
            if(dis[t]+w[i]<dis[j])//���ڸ���·��
            {
                dis[j]=dis[t]+w[i];//����
                if(!vis[j])//���ٶ�����
                {
                    q.push(j);//���
                    vis[j]=true;//���
                }
            }
        }
        
    }
}
int main()
{
    cin>>n>>m>>S>>T;//����
    
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    for(int i=0;i<m;i++)//����ͼ
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);//����ͼ
    }
    
    spfa();
    
    cout<<dis[T];
    return 0;
    
}
