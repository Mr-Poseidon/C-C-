#include<iostream>
using namespace std;

typedef unsigned long long ull;//unsigned long long Ϊ 2^64,����Զ�ȡģ

const int N=100010,P=131;//PΪ�̶�ֵ����ͻ������С������û��

ull h[N],p[N];//h[]��ϣֵ��ֵ��Ϊ0~2^64-1��p[]�洢P��i�η�ֵ
char s[N];//�ַ����±���1��ʼ��0���ò���

ull gethash(int l,int r)//��ȡ����[l,r]�����ַ����Ĺ�ϣֵ
{
    //���ڵ�λ���ַ�ʵ�����Ǹ�λ�Ĺ�ϣֵ�����Ե�λ�ַ���Ҫ����P[r-l+1]
    return h[r]-h[l-1]*p[r-l+1];// r-(l-1)=r-l+1
}

int main()
{
    int n,m;
    cin>>n>>m;
    cin>>s+1;
    
    p[0]=1;//P��0�η�Ϊ1
    for(int i=1;i<=n;i++)//�����ַ����Ĺ�ϣֵ
    {
        h[i]=h[i-1]*P+s[i];//�ַ����Ĺ�ϣֵ���������ַ����Ĺ�ϣֵ����
        p[i]=p[i-1]*P;//�洢P�Ĵη���
    }
    
    for(int i=0;i<m;i++)//��ѯ
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(gethash(l1,r1)==gethash(l2,r2))puts("Yes");
        else puts("No");
    }
    return 0;
}

