#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=110;

int a[N];
int f[N],g[N];//f[]ά����ǰ������������ֵ��g[]ά���Ӻ���ǰ���������ֵ
int n;


int main()
{
    int T;
    scanf("%d",&T);//������������
    
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);//��������
        
        int ans=0;//���
        for(int i=1;i<=n;i++)//��ǰ����
        {
            f[i]=1;//���ٳ���Ϊ1
            for(int j=1;j<i;j++)//����ǰ���ֵ
                if(a[j]<a[i])//���ȵ�ǰС���������Խ��ں���
                    f[i]=max(f[i],f[j]+1);//״̬ת��
            
            ans=max(ans,f[i]);//�����ֵ
        }
        
        for(int i=n;i;i--)//�Ӻ���ǰ
        {
            g[i]=1;
            for(int j=n;j>i;j--)
                if(a[j]<a[i])
                    g[i]=max(g[i],g[j]+1);
            
            ans=max(ans,g[i]);
        }
        
        printf("%d\n",ans);//������
    }
    return 0;
}
