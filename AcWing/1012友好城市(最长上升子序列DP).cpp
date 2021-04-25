#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=5010;
typedef pair<int,int> PII;


//����������һ������Ϊ�ο�������������һ������ ����������� ��Ϊ��

PII q[N];
int f[N];
int n;

int main()
{
    scanf("%d",&n);//��������
    for(int i=1;i<=n;i++)scanf("%d%d",&q[i].first,&q[i].second);
    
    sort(q+1,q+1+n);//����
    
    int ans=0;
    
    for(int i=1;i<=n;i++)//��ǰ���� �� �����������
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(q[j].second<q[i].second)
                f[i]=max(f[i],f[j]+1);
        ans=max(ans,f[i]);//��¼���ֵ
    }
    
    printf("%d",ans);//������
    return 0;
}
