#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+10;

ll f[N],s[N];//f[i]ά��ǰiͷţ�����ŷ�����s[i]ά��ǰiͷţ��Ч��ǰ׺��
int n,m;
int q[N],hh,tt;//ά����������

/*
    ѡ���iͷţ�����:f[i]=f[i-j-1]+s[i]-s[i-j],1<=j<=m
    ��Ϊj�Ǳ�������ʽ����Ϊ��f[i]=(f[i-j-1]-s[i-j]) + s[i],�� f[i-j-1]-s[i-j] ����һ��������
    Ϊ�˷��㣬�� f[i-j-1]-s[i-j] ��װ��һ������g(i-j) = f[i-j-1]-s[i-j] ����i-j����һ�����壬����g(i)=f[i-1]-s[i];
    ��ѡ�������f[i]=f[i-1]
    
    ��Ϊ�������ֵ������ f[i] = max( f[i-1] , g(q[hh])+s[i] )
*/

ll g(int i)//�� f[i-j-1]-s[i-j] ��װ��һ������g(i-j) = f[i-j-1]-s[i-j] 
{
    return f[i-1]-s[i];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)//��������
    {
        cin>>s[i];
        s[i]+=s[i-1];//ά��ǰ׺��
    }
    
    hh=tt=0;
    q[tt++]=0;//��0��Ҳ���ȥ������״̬ת��
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-m)hh++;//����
        f[i]=max(f[i-1],g(q[hh])+s[i]);//ά�����ֵ
        while(hh<tt && g(q[tt-1])<g(i))tt--;//ά�� f[i-j-1]-s[i-j] �����ֵ
        q[tt++]=i;//���
    }
    
    cout<<f[n];//������
    return 0;
}

