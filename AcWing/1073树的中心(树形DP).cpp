#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=10010,M=N*2,INF=0x3f3f3f3f;


int h[N],e[M],w[M],ne[M],idx;//�ڽӱ�ά���� 
int d1[N],d2[N],p1[N],p2[N];//d1,d2ά������γ�·�����ȣ�P1,p2ά������γ�·���ķ��� 
int up[N];//upά�������ߵ�·������ 
int n;

void add(int a,int b,int c)//�����ڽӱ� 
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs_d(int u,int father)//�������ߵ��·��
{
    d1[u]=d2[u]=-INF;//�����ߵ�����·����ʼ��
    
    for(int i=h[u];i!=-1;i=ne[i])//����ÿ���ӽڵ�
    {
        int j=e[i];
        if(j==father)continue;//���ڵ������
        
        int d=dfs_d(j,u)+w[i];//����ӽڵ���·��+�ñ�Ȩֵ�����Ǳ����ڵ���·��
        
        if(d>=d1[u])//����·�����������
        {
            d2[u]=d1[u],d1[u]=d;//ά�������·��
            p2[u]=p1[u],p1[u]=j;//ά��·���ķ���
        }
        else if(d>d2[u])d2[u]=d,p2[u]=j;//ά���γ�·���뷽��
    }
    
    if(d1[u]==-INF)d1[u]=d2[u]=0;//û�и��¡�˵����Ҷ�ӽڵ㡢���µ�����γ�·����Ϊ0
    
    return d1[u];//���������·��
}

void dfs_u(int u,int father)//�������ߵ��·��
{
    //if(father==-1)up[u]=0;//���ڵ����ϵ�·��Ϊ0
    
    for(int i=h[u];i!=-1;i=ne[i])//���������ӽڵ�
    {
        int j=e[i];
        if(j==father)continue;//���ڵ������
        
        //�ӽڵ������ߵ����·��=max(���ڵ������·�� , ���ڵ������·�������а��������ӽڵ㣬ע��������)
        /*
            ����ӽڵ� �� ���ڵ������·���е�һ���ڵ㣬�ӽڵ�����·����Ϊ��
                max(���ڵ�γ�����·�������ڵ�����·��)+��Ȩֵ
            ��������ӽڵ� ���� ���ڵ������·���е�һ���ڵ㣬�ӽڵ�����·����Ϊ��
                max(���ڵ������·�������ڵ�����·��)+��Ȩֵ)
        */
        if(p1[u]==j)up[j]=max(up[u],d2[u])+w[i];//�ӽڵ����·����
        else up[j]=max(up[u],d1[u])+w[i];//�ӽڵ㲻���·����
        
        dfs_u(j,u);//�������¸��� �ӽڵ���ӽڵ� �����ߵ�·��
    }
}

int main()
{
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    
    cin>>n;//����
    for(int i=0;i<n-1;i++)//�����ڽӱ�
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);//����ߡ���������
    }
    
    dfs_d(1,-1);//������������������ߵ�·��
    
    dfs_u(1,-1);//���������ߵ�·��
    
    int ans=INF;
    for(int i=1;i<=n;i++)ans=min(ans,max(up[i],d1[i]));//�����߻��������������ֵ���ٴ����ֵ��ά����Сֵ
    
    cout<<ans;//������
    return 0;
}
