#include<iostream>
using namespace std;

typedef long long ll;//�����ݳ˷����ܻ���������������ll

int qmi(int a,int k,int p)//������
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%p;
        k>>=1;
        a=(ll)a*a%p;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,p;
        scanf("%d%d",&a,&p);
        
        if(a%p==0)puts("impossible");//���a��p�ı�������ô�޽�
        else printf("%d\n",qmi(a,p-2,p));//�����Ԫ
    }
    return 0;
}
