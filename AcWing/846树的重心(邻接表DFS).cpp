#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int h[N],e[2*N],ne[2*N],idx;//�ڽӱ�(�ڵ�����һģһ��)
int n,ans=N;
bool vis[N];//�жϸýڵ��Ƿ������


void insert(int k,int x)//�ڽӱ�������
{
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

int dfs(int k)//����
{
    vis[k]=true;
    
    int sum=1,res=0;//sum�����Ըýڵ�Ϊ���������ܽڵ������ýڵ㱾��Ϊ1
    
    for(int i=h[k];i!=-1;i=ne[i])//�����ýڵ����ӵ���������
    {
        int j=e[i];//ȡֵ
        if(!vis[j])//�õ�δ������
        {
            int t=dfs(j);//����
            res=max(res,t);//ȡ���������ڵ���
            sum+=t;//���������Ľڵ���
        }
        
    }
    res=max(res,n-sum);//n-sumΪȥ���Ըýڵ�Ϊ����������һ�����Ľڵ���
    ans=min(ans,res);//ȡ��С�Ľڵ���
    return sum;//�����Ըõ�Ϊ���ڵ�����Ľڵ���
}

int main()
{
    cin>>n;
    
    memset(h,-1,sizeof(h));//��ʼ���ڽӱ�-1Ϊ��β
    
    for(int i=0;i<n;i++)//����
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);
        insert(b,a);
    }
    
    dfs(1);//����
    
    cout<<ans;//���
    
    return 0;
}
