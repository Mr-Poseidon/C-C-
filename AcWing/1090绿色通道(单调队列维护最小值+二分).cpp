#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=50010;

int f[N],w[N];//f[i]ά��ǰi��������Сֵ��w[i]ά����i���Ȩֵ
int n,T;
int q[N],hh,tt;//ά����������

bool check(int len)//�жϿյĳ���Ϊlen�Ƿ����ʵ��
{
    hh=tt=0;
    q[tt++]=0;
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-len-1)hh++;//���Կյĳ���Ϊlen�����Կ���ȡ��ǰ����һ����������-1
        f[i]=f[q[hh]]+w[i];//ʵ�ֽ���ۼ�
        while(hh<tt && f[q[tt-1]]>f[i])tt--;//ά��������Сֵ
        q[tt++]=i;
    }
    
    for(int i=n-len;i<=n;i++)//�ж��Ƿ����<=T��ֵ������˵��������ȿ���ʵ��
        if(f[i]<=T)
            return true;
    return false;
}
int main()
{
    cin>>n>>T;
    for(int i=1;i<=n;i++)cin>>w[i];
    
    int l=0,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;//�����󳤶������ж��١�������Сֵ�������ͱ�С
        else l=mid+1;//��������
    }
    
    cout<<l<<endl;//��������l��r������
    return 0;
    
}
