#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=200010;

int f[N],w[N];//f[i]ά��ǰi�����̨��ѡ�����Сֵ��w[i]ά����i�����̨��Ȩֵ
int n,m;
int q[N],hh,tt;//ά����������

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];//����
    
    hh=tt=0;
    q[tt++]=0;//��0�����̨Ҳ��
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-m)hh++;//<�����ڱ���ǰ���m������ά����Сֵ��<=���ڱ���ǰ��m-1������ά����Сֵ
        f[i]=f[q[hh]]+w[i];//��ǰ��m������ȡ��Сֵ���ϱ����Ȩֵ����ʵ�� ״̬�ۼ�
        while(hh<tt && f[q[tt-1]]>f[i])tt--;//����
        q[tt++]=i;//���
    }
    
    int ans=2e9;
    for(int i=n-m+1;i<=n;i++)ans=min(ans,f[i]);//ά����Сֵ
    cout<<ans;
    return 0;
}

