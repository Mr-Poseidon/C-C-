#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=50010;

int h[N],e[N],ne[N],idx;//�ڽӱ�ά����
int sum[N];//sum[i]ά����i��������
bool son[N];//son[i]�ж���i�ǲ����ӽڵ㡢true�ǡ�false����
int n;
int ans;//ά����

void add(int a,int b)//�����ڽӱ�
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u)//����
{
    int d1=0,d2=0;//����γ�����
    
    for(int i=h[u];~i;i=ne[i])//ö�������ӽڵ�
    {
        int j=e[i];
        int d=dfs(j)+1;//�����ӽڵ�ı任���� + 1���ڱ����ı任����
        
        if(d>d1)d2=d1,d1=d;//��������γ�����
        else if(d>d2)d2=d;
    }
    ans=max(ans,d1+d2);//����ֱ��
    
    return d1;//���������
}

int main()
{
    memset(h,-1,sizeof(h));//��ʼ���ڽӱ�
    
    cin>>n;
    for(int i=1;i<=n;i++)//ö������
        for(int j=2;j<=n/i;j++)//ö��i��j����
            sum[i*j]+=i;//����i*j������i
    
    for(int i=2;i<=n;i++)//��2��ʼö�٣���Ϊ1��������Ϊ0���任���ֱ���Ϊ������������1����
        if(i>sum[i])//�����i������i��������
        {
            add(sum[i],i);//���
            son[i]=true;//���
        }
    
    for(int i=1;i<=n;i++)//�������еĵ�
        if(!son[i])//��Ϊ�ӽڵ㡢��Ϊ���ڵ�
            dfs(i);//����
    
    cout<<ans;//������
    return 0;
}

