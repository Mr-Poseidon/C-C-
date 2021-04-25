#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=10010,M=20010;

int h[N],e[M],w[M],ne[M],idx;//�ڽӱ�ά���� 
int n;
int ans;//ά��ֱ��

void add(int a,int b,int c)//�����ڽӱ�
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)//����
{
    //��ʼ��Ϊ0���Ա��⸺Ȩ·��
    int dist=0;//����ӵ�ǰ�ڵ������ߵ��·��
    int d1=0,d2=0;//���������ߵ������·���ʹγ�·��
    
    for(int i=h[u];i!=-1;i=ne[i])//����ÿһ���ӽڵ�
    {
        int j=e[i];
        if(j==father)continue;//����һ���ڵ��Ǹ��ڵ㡢������
        int d=dfs(j,u)+w[i];//��һ���������ߵ��·��+����֮���Ȩֵ
        dist=max(dist,d);//�ж��ǲ����
        
        if(d>=d1)d2=d1,d1=d;//ά�������·��
        else if(d>d2)d2=d;
    }
    
    ans=max(ans,d1+d2);//ά���ֱ���������ֱ������ĵ�ͻ���£����򲻻����
    return dist;
}
int main()
{
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    
    cin>>n;//����
    for(int i=0;i<n-1;i++)//�����ڽӱ�,ע�⣺ֻ��n-1�������
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);//���ı�������ߡ�����Ҫ����������
        add(b,a,c);
    }
    
    dfs(1,-1);//����
    
    cout<<ans;//������
    return 0;
}

