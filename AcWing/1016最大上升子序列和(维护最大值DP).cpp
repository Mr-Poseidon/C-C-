#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N];//ά������
int f[N];//ά��������е����ֵ
int n;

int main()
{
    scanf("%d",&n);//��������
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=a[i];//����Ҳ��һ�����С����ֵΪ����
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+a[i]);//״̬ת�Ʒ���
        ans=max(ans,f[i]);//��¼���ֵ
    }
    
    printf("%d",ans);//������
    return 0;
}
