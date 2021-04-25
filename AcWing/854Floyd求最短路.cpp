#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=210,INF=0x3f3f3f3f;

int d[N][N];//d[i][j]����i��j�ľ���
int n,m,q;


void floyd()//floyd�㷨��ʱ�临�Ӷ�O(N^3)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    for(int i=1;i<=n;i++)//�ڽӾ����ʼ��
        for(int j=1;j<=n;j++)
            if(i==j)d[i][j]=0;//i==j����һ����
            else d[i][j]=INF;
    
    while(m--)//�����
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b]=min(d[a][b],c);//�ر�ά����Сֵ
    }
    
    floyd();
    
    while(q--)//��ѯ
    {
        int a,b;
        scanf("%d%d",&a,&b);
        
        //��Ȩ����Ϊ����������ֻҪ����INF-200*20000��Ϊ������
        if(d[a][b]>INF/2)puts("impossible");//��������
        else printf("%d\n",d[a][b]);//����
    }
    
    return 0;
}
