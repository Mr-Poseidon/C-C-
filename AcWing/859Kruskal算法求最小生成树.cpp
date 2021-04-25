#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=200010;

struct Edge{
    int a,b,w;//����a��b��ȨֵΪw
    
    bool operator<(const Edge &e)const{
        return w<e.w;
    }
}e[M];//ά���ߵ�����

int par[N];//ά�����鼯
int n,m;

int find(int x)//���
{
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++)//�����
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        e[i]={a,b,w};
    }
    
    sort(e,e+m);//����
    for(int i=0;i<=n;i++)par[i]=i;//���鼯��ʼ��
    
    //sum������С��������ֵ��cnt�������бߵ�����
    //��С������һ����n-1���߹��ɡ�������С��n-1˵��ͼ����ȫ��ͨ,�޷�������С������
    int sum=0,cnt=0;
    for(int i=0;i<m;i++)//����ÿһ����
    {
        int a=e[i].a,b=e[i].b,w=e[i].w;
        
        a=find(a),b=find(b);
        if(a!=b)//������ͬһ�������С�˵����δ��ͨ
        {
            par[a]=b;//�ϲ�
            sum+=w;//Ȩֵ������С��������
            cnt++;//����+1
        }
    }
    
    if(cnt<n-1)puts("impossible");//��������С������
    else printf("%d",sum);//���ڡ����
    
    return 0;
}
