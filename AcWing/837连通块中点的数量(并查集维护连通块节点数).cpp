#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=100010;

//par[k]Ϊk�ڵ�ĸ��ڵ㣬si[k]Ϊk�ڵ�������ͨ���е������
int par[N],si[N];
int n,m;

int find(int x)//���Ҹ��ڵ�
{
    if(par[x]==x)return x;
    return par[x]=find(par[x]);//·��ѹ��
}

bool same(int a,int b)//�ж��Ƿ���ͨ
{
    return find(a)==find(b);
}

void merge(int a,int b)//�ϲ�
{
    a=find(a);
    b=find(b);
    if(a==b)return;//�Ѿ���ͨ�򷵻�
    
    par[a]=b;//��a������ͨ�鲢��b��
    si[b]+=si[a];//ά��b��ͨ���е������
    return;
}



int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)par[i]=i,si[i]=1;
    
    char op[10];
    int a,b;
    
    while(m--)
    {
        scanf("%s",op);
        
        if(!strcmp(op,"C"))//�ϲ�����
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else if(!strcmp(op,"Q1"))//��ѯ�Ƿ���ͨ����
        {
            scanf("%d%d",&a,&b);
            if(same(a,b))puts("Yes");
            else puts("No");
        }
        else//��ѯ��ͨ���еĵ���
        {
            scanf("%d",&a);
            printf("%d\n",si[find(a)]);
        }
    }
    return 0;
}
