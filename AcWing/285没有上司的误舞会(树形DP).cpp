#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=6010;

int h[N],e[N],ne[N],idx;//ά���ڽӱ�
int happy[N];//ά��ÿ���˵Ŀ���ֵ
int f[N][2];//f[i][0]���� ��ѡ i����˵Ŀ���ֵ��f[i][1]���� ѡ i����˵Ŀ���ֵ
bool has_father[N];//ά��ĳ���Ƿ��и��ڵ�
int n;

void insert(int a,int b)//�����ڽӱ�
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int k)//����
{
    if(f[k][0]!=0)return;//����õ��Ѿ��߹���ֱ�ӷ���
    
    f[k][1]=happy[k];//ѡ��k�����Ҫ����k�Ŀ���ֵ
    
    for(int i=h[k];i!=-1;i=ne[i])//����k���ӽڵ�
    {
        int j=e[i];
        
        dfs(j);//����j��
        
        f[k][0]+=max(f[j][0],f[j][1]);//��ѡkʱ��k���ӽڵ����ѡҲ���Բ�ѡ
        f[k][1]+=f[j][0];//ѡkʱ��k���ӽڵ�ֻ�ܲ�ѡ
    }
}

int main()
{
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>happy[i];//����ÿ���˵Ŀ���ֵ
    
    for(int i=0;i<n-1;i++)//�����ڽӱ�
    {
        int a,b;
        cin>>a>>b;
        insert(b,a);
        has_father[a]=true;//��¼�õ��и��ڵ�
    }
    
    int root;
    for(int i=1;i<=n;i++)//�ҵ����ڵ㣬����˾
        if(!has_father[i])
            root=i;
    
    dfs(root);//�ɸ��ڵ㿪ʼ��������
    
    printf("%d",max(f[root][0],f[root][1]));//���ڵ�ѡ�벻ѡ�����ֵ��Ϊ��
    return 0;
}

