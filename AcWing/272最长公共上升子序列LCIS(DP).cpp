#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=3010;

int a[N],b[N];//ά��a,b��������
int f[N];//ά����b[i]��β�� ��������������� ��ֵ
int n;


int main()
{
    scanf("%d",&n);//���� 
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    
    for(int i=1;i<=n;i++)
    {
        int maxv=0;//ά��ǰ׺ ��������������� �����ֵ
        for(int j=1;j<=n;j++)
        {
            //�˴���Ϊa[i]==b[j]�ǲŻ����ֵ����+1
            //b[j]<b[i] ��ʾ b[i] ���Է��� b[j] ���棬�����µĹ���������
            //����b[j]<b[i] �ȼ��� b[j]<a[i], �˴���һ���Ż���
            //ע�⣺�������Ʊ���,���¡��Ƚϵ�ֵ����f[j]
            
            if(b[j]<a[i])maxv=max(maxv,f[j]);//�ж����ֵ�ܷ���£��ܵĻ��͸���
            if(b[j]==a[i])f[j]=maxv+1;//b[j]==a[i]ʱ�����׶�+1��ֵ����
        }
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);//�������ֵ
    
    printf("%d",ans);//������
    return 0;
}
