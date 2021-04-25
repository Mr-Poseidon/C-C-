#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;

int h[N],e[N*2],ne[N*2],idx;//�ڽӱ�
int q[N],hh,tt;//ģ�����

int in[N];//���
int n,m;

void insert(int a,int b)//�����ڽӱ�
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int topsort()//��������
{
    //���������Ϊ0�ĵ����
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q[tt++]=i;
        
    while(hh<tt)
    {
        int p=q[hh++];
        
        for(int i=h[p];i!=-1;i=ne[i])//����p����������нڵ�
        {
            int j=e[i];
            in[j]--;//�õ����-1
            
            if(in[j]==0)q[tt++]=j;//���Ϊ0�����
        }
    }
    
    return tt==n;//һ����ttΪn˵����n-1������ӡ�ȫ���ڵ���ӣ�������������
}

int main()
{
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);//����ͼֻ����һ��
        in[b]++;//��Ƚڵ�+1
    }
    
    if(topsort())//������������
    {
        for(int i=0;i<n;i++)printf("%d ",q[i]);//���
        puts("");
    }
    else puts("-1");//��������������
    
    return 0;
}

