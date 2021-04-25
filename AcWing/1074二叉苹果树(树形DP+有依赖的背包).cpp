#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110,M=N*2;

int h[N],e[M],w[M],ne[M],idx;//�ڽӱ�ά����
int f[N][N];//f[i][j]ά��i�����ѡ��j����֦�����ֵ
int n,m;//n���㡢m����֦

void add(int a,int b,int c)//�����ڽӱ�
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)
{
    for(int i=h[u];~i;i=ne[i])//ö��ÿһ���ӽڵ�
    {
        if(e[i]==father)continue;//�������ڵ�
        
        dfs(e[i],u);//����
        
        //f[u][j]=max(f[u][j],f[u][j-k-1]+f[e[i]][k]+w[i]);
        //                    ���ڵ�ѡ��j-k-1����֦���ӽڵ�ѡ��k����֦��-1����Ϊ��Ҫ���ϱ��ε���֦(Ȩֵ)
        for(int j=m;j>0;j--)//ö�ٱ������------���Ϊ0����Ϊ��ѡ��ֵ��Ϊ0
            for(int k=0;k<=j-1;k++)//ö����Ʒ����------�ӽڵ����ѡj-1������Ϊ����ҲҪռһ��
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[e[i]][k]+w[i]);//״̬ת�Ʒ���
    }
}

int main()
{
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    
    cin>>n>>m;//����
    for(int i=0;i<n-1;i++)//�����ڽӱ�
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    dfs(1,-1);//����
    
    cout<<f[1][m];//������
    return 0;
}
