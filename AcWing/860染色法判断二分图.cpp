#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=200010;//����ͼ�����Աߵ�����Ҫ��2��

int h[N],e[M],ne[M],idx;//�ڽӱ�
int color[N];//ά��ÿ�������ɫ
int n,m;

void add(int a,int b)//�����ڽӱ�
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)//u����㣬c������ɫ
{
    color[u]=c;//Ⱦɫ
    
    for(int i=h[u];i!=-1;i=ne[i])//�����õ����е��ڽӱ�
    {
        int j=e[i];
        if(!color[j])//δȾɫ
        {
            if(!dfs(j,c*-1))return false;//���ѡ����ұ任��ɫ������ͻ������false
        }
        else if(color[j]==c)return false;//�Ѿ�Ⱦɫ�����ڽӵ��ͻ������false
    }
    return true;//�õ����е��ڽӵ�Ⱦɫ����ȷ������true
}

int main()
{
    memset(h,-1,sizeof h);//�ڽӱ��ʼ��
    scanf("%d%d",&n,&m);
    
    while(m--)//�����
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);//����ͼҪά��������
    }
    
    bool f=true;//��Ǳ���
    for(int i=1;i<=n;i++)//�������еĵ�
    {
        if(!color[i])//���û��Ⱦɫ
        {
            if(!dfs(i,1))//����Ⱦɫ�����ڳ�ͻ
            {
                f=false;//�ı���
                break;
            }
        }
    }
    
    if(f)puts("Yes");//�Ƕ���ͼ
    else puts("No");//���Ƕ���ͼ
    
    return 0;
}
