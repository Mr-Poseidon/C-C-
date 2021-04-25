#include<iostream>
using namespace std;

typedef long long ll;//快速幂乘法可能会造成数据溢出、开ll

int qmi(int a,int k,int p)//快速幂
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
        
        if(a%p==0)puts("impossible");//如果a是p的倍数，那么无解
        else printf("%d\n",qmi(a,p-2,p));//输出逆元
    }
    return 0;
}
