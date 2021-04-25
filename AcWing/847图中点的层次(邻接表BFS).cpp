#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;

int n,m;

int h[N],e[2*N],ne[2*N],idx;//�ڽӱ�
bool vis[N];//�ж��Ƿ���ʹ�

int q[N],hh,tt;//ģ�����
int d[N];//�洢����


void insert(int k,int x)//�����ڽӱ�
{
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

void bfs()
{
    
    d[1]=0;//��1��ʼ��1�ľ���Ϊ0
    vis[1]=true;//���
    q[0]=1;//���
    
    while(hh<=tt)
    {
        int p=q[hh++];//����
        
        if(p==n)//�ѵõ�
        {
            cout<<d[p];
            return;
        }
        
        for(int i=h[p];i!=-1;i=ne[i])//����
        {
            int j=e[i];//�ڽӵĽڵ�
            if(!vis[j])//δ���ʹ�
            {
                d[j]=d[p]+1;//����+1
                vis[j]=true;//���
                q[++tt]=j;//���
            }
        }
    }
    cout<<"-1";//�Ѳ���
    return;
}

int main()
{
    memset(h,-1,sizeof(h));//��ʼ���ڽӱ�
    
    cin>>n>>m;//����
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);//����ͼֻ����һ��
    }
    
    bfs();//����
    
    return 0;
}
