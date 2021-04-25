#include<iostream>
#include<cstdio> 
using namespace std;

typedef unsigned long long ull;

const int N=1000003,P=131;
ull h[N],p[N];//h[]��ģʽ���Ĺ�ϣ��p[]����ƵĴη���

int n,m;
char s[N],ps[N];//s[]ģʽ����ps[]ģ�崮

ull gethash(int l,int r)//��ȡģʽ��ĳ���Ӵ��Ĺ�ϣֵ
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    scanf("%d%s",&n,ps+1);//����ģ�崮
    scanf("%d%s",&m,s+1);//����ģʽ��
    
    p[0]=1;
    for(int i=1;i<=m;i++)//����ģʽ���Ĺ�ϣֵ��
    {
        h[i]=h[i-1]*P+s[i];
        p[i]=p[i-1]*P;
    }
    
    ull psh=0;
    for(int i=1;i<=n;i++)//����ģ�崮�Ĺ�ϣֵ
        psh=psh*P+ps[i];
    
    for(int i=1;i+n-1<=m;i++)//ƥ��
        if(gethash(i,i+n-1)==psh)
            printf("%d ",i-1);
    
    return 0;
}
 
