#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,M=10005;

//��
struct Edge{
    int a,b,w;//w����a�㵽b��ľ���
}e[M];

int dis[N],backup[N];//disά�����ε����ľ��룬backupά����һ�ε����ľ���
int n,m,k;//n���������m���������k������಻�����������ߣ������ĵ���������


//bellman_ford�㷨���ص㣺�������ƾ����ıߵ�����
//�㷨ʱ�临�Ӷ�O(nm) 
int bellman_ford(int a,int b)//a������㣬b�����յ�
{
    memset(dis,0x3f,sizeof dis);//��ʼ������
    dis[a]=0;//������Ϊ0
    
    for(int i=0;i<k;i++)//����
    {
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++)//�������еı�
        {
            int a=e[j].a,b=e[j].b,w=e[j].w;
            if(dis[b]>backup[a]+w)//�ɳ�����
                dis[b]=backup[a]+w;
        }
    }
    
    //���������ڸ�Ȩ������ȥ��ֵ��󲻳���500*10000=5e6,���Դ���5e6��Ϊ�޷�����
    if(dis[b]>0x3f3f3f3f/2)return -1;
    else return dis[b];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=0;i<m;i++)//�����
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }
    
    int t=bellman_ford(1,n);
    
    if(t==-1)puts("impossible");//������
    else printf("%d",t);
    
    return 0;
}
