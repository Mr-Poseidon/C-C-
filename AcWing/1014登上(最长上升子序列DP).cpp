#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N];
int f[N],g[N];
int n;

int main()
{
    scanf("%d",&n);//��������
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++)//�����ǰ����������������
    {
        f[i]=1;//����ĳ���Ϊ1
        for(int j=1;j<i;j++)//����ǰ���ֵ
            if(a[j]<a[i])//��ǰ���ֵ�����ڵ�С��˵�����ڵ�ֵ�ܷ��ں���
                f[i]=max(f[i],f[j]+1);//״̬ת�Ʒ���
    }
    
    for(int i=n;i;i--)//�Ӻ���ǰ
    {
        g[i]=1;
        for(int j=n;j>i;j--)
            if(a[j]<a[i])
                g[i]=max(g[i],g[j]+1);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)//�������еĵ㡢����һ������Ϊ�ߵ�����ߵľ���ȽϺ�
        ans=max(ans,f[i]+g[i]-1);//��ߵ㱻�������Ρ�����-1
    
    printf("%d",ans);//�����
    return 0;
}
