#include<iostream>
using namespace std;

typedef long long ll;

int qmi(int a,int k,int p)//快速幂函数
{
    int ans=1;
    while(k)
    {
        //乘法计算可能数据溢出、要开long long
        if(k&1)ans=(ll)ans*a%p;//次方进制位为1,乘上该位的a次方
        k>>=1;//次方位右移一位
        a=(ll)a*a%p;//底数自乘翻倍
    }
    return ans;//返回结果
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);//输入
        printf("%d\n",qmi(a,k,p));//输出快速幂
    }
    return 0;
}
