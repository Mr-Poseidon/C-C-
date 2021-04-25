#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;


//对于数值num,最多只存在一个大于等于num的质因子
//质因子：既是质数、又是因数
//时间复杂度O(sqrt(n))
void divisor(int num)
{
    for(int i=2;i<=num/i;i++)//遍历所有的数
        if(num%i==0)//如果是因数
        {
            int sum=0;
            while(num%i==0)//计算因数的个数
            {
                num/=i;//除掉该数的质因数i
                sum++;
            }
            printf("%d %d\n",i,sum);//输出
        }
    
    if(num>1)printf("%d %d\n",num,1);//如果存在最后一个大于1的质因子，输出
    puts("");//换行
}


int main()
{
    scanf("%d",&n);
    
    while(n--)
    {
        int t;
        scanf("%d",&t);
        divisor(t);
    }
    return 0;
}
