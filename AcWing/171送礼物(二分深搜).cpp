#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=50;

int n,m;//n����Ʒ���ܳ��ܵ��������Ϊm
int w[N];//ά��������Ʒ������
int weights[1<<25],cnt;//ά����һ�����������п��ܳ��ֵĽ��
int ans=0;//ά�����ֵ

void dfs1(int u,int s,int k)//u�����ѵ���u������s����ǰ�漸��������Ȩֵ��k����ֻ����k����
{
    if(u==k)//Խ��
    {
        weights[cnt++]=s;//��¼
        return;
    }
    
    dfs1(u+1,s,k);//��ѡ��u����
    if(s<=m-w[u])dfs1(u+1,s+w[u],k);//ѡ���u�����������Լ�֦��s+w[u]<=m,Ϊ�˷�ֹ�����д�ɣ�s<=m-w[u]
}

void dfs2(int u,int s)
{
    if(u==n)
    {
        int k=upper_bound(weights,weights+cnt,m-s)-weights;//���ֲ��ң����ش���m-s�ĵ�һ��ֵ������
        ans=max(ans,s+weights[k-1]);//ά�����ֵ��k-1��ΪС�ڵ���m-s��������������
        return;
    }
    
    dfs2(u+1,s);//��ѡ��u����
    if(s<=m-w[u])dfs2(u+1,s+w[u]);//ѡ���u�����������Լ�֦��s+w[u]<=m,Ϊ�˷�ֹ�����д�ɣ�s<=m-w[u]
}

int main()
{
    cin>>m>>n;//����
    for(int i=0;i<n;i++)cin>>w[i];
    
    //�Ż�����˳�򣬴Ӵ�С��ʼ����
    sort(w,w+n);//��С��������
    reverse(w,w+n);//��ת
    
    int k=n/2+2;//��������
    
    dfs1(0,0,k);//��һ������
    
    sort(weights,weights+cnt);//����
    cnt=unique(weights,weights+cnt)-weights;//ȥ��
    
    dfs2(k,0);//�ڶ�������
    
    cout<<ans;//������
    return 0;
}

