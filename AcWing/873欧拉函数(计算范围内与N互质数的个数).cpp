#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

//由于本题只需要用到质因数、不需要用到质因数的次幂、所以没有开unordered_map
int n;

/*
   计算1~N之间与N互质的数的个数
   若用gcd的方法求,遍历每一个数，判断是否互质,算法复杂度为O(N)
   若用欧拉函数、算法复杂度优化到O(sqrt(N))
*/

int main()
{
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        
        int ans=num;//结果初始化是num
        
        for(int i=2;i<=num/i;i++)//分解质因数
        {
            if(num%i==0)
            {
                ans=ans/i*(i-1);//计算欧拉函数，先除再乘可以避免数据溢出
                while(num%i==0)num/=i;//分解质因数
            }
        }
        if(num>1)ans=ans/num*(num-1);//存在大于等于sqrt(num)的质因数
        
        cout<<ans<<endl;//输出
    }
    return 0;
}
