#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=100010;

int h[N],e[N],w[N],ne[N],idx;
int dis[N];
bool vis[N];//�ж�ĳ�����ǲ����ڶ���
int n,m;

void insert(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}


//spfa���㷨���Ӷ�ΪO(m),�����˻�ΪO(nm)
//���㷨�ڳ��ָ�Ȩ����ʱ�򾡹ܻ���ֶ������ࡢ�����������ѭ�� 
//spfa�㷨������ ����dijkstra �� ���Ż����dijkstra ֮���һ�������㷨 
int spfa(int a,int b)
{
    memset(dis,0x3f,sizeof(dis));//��ʼ��
    dis[a]=0;//������Ϊ0
    
    //����������Ӻͱ��,�����д�ž��뱻�ɳڹ��ĵ�
    queue<int> q;
    q.push(a);
    vis[a]=true;
    
    while(!q.empty())
    {
        int t=q.front();//����
        q.pop();
        vis[t]=false;
        
        for(int i=h[t];i!=-1;i=ne[i])//�������иõ���Ե���ĵ�
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])//�����ɳ�
            {
                dis[j]=dis[t]+w[i];
                if(!vis[j])//������ڶ���
                {
                    vis[j]=true;//���
                    q.push(j);//���
                }
            }
        }
    }
    
    //���ڸ�Ȩ��,����dis>0x3f3f3f3f-1e9��Ϊ���ɵ���
    if(dis[b]>0x3f3f3f3f/2)return -1;
    else return dis[b];
}

int main()
{
    memset(h,-1,sizeof(h));//��ʼ���ڽӱ�
    scanf("%d%d",&n,&m);
    
    while(m--)//�����
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        insert(a,b,w);
    }
    
    int t=spfa(1,n);
    
    if(t==-1)puts("impossible");
    else printf("%d",t);
    
    return 0;
}
