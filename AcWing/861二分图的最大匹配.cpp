#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,M=100010;

int h[N],e[M],ne[M],idx;//�ڽӱ�
int match[N];//�Ұ벿��ƥ�����벿�ĵ�
bool vis[N];//�ж��Ƿ���ʹ�
int n1,n2,m;

void add(int a,int b)//�����ڽӱ�
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x)//��ѯ��벿x���ƥ�����
{
    for(int i=h[x];i!=-1;i=ne[i])//�����ڽӱ�
    {
        int j=e[i];
        if(!vis[j])//δ���ʹ�
        {
            vis[j]=true;//���
            //match���Դ洢֮ǰ��벿���ƥ�����
            if(match[j]==0 || find(match[j]))//����Ұ벿�ĵ�δƥ����ߴ�������ƥ��
            {
                match[j]=x;//ƥ��
                return true;//���ؿ���ƥ��
            }
        }
    }
    return false;//�޷�ƥ��
}

int main()
{
    memset(h,-1,sizeof(h));
    
    scanf("%d%d%d",&n1,&n2,&m);
    
    while(m--)//�����
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int ans=0;
    for(int i=1;i<=n1;i++)//������벿�ĵ�
    {
        memset(vis,false,sizeof vis);//��ʼ���������
        if(find(i))ans++;//����ƥ��
    }
    
    printf("%d",ans);//�����
    return 0;
}
