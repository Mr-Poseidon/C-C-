#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=100010;

int par[N];//par[k]���k�ĸ��ڵ�

int find(int x)//���
{
    if(x==par[x])return x;
    return par[x]=find(par[x]);//·��ѹ��
}

void merge(int a,int b)//�ϲ�
{
    a=find(a);
    b=find(b);
    if(a==b)return;
    
    par[b]=a;
    return;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)par[i]=i;//��ʼ��
    
    char op[2];
    int a,b;
    while(m--)
    {
        scanf("%s",op);
        
        if(op[0]=='M')
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else
        {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))puts("Yes");//�ж��Ƿ���ͨ
            else puts("No");
        }
    }
    return 0;
}
