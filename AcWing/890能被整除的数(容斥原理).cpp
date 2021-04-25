#include<iostream>
using namespace std;

const int N=20;
typedef long long ll;

/*
    容斥原理刚好可以转换成状态压缩中的所有状态
    当状态中的元素个数为 奇数 时刚好对应容斥原理中的 + 的情况
    当状态中的元素个数为 偶数 时刚好对应容斥原理中的 - 的情况
*/

int primes[N];//维护质数数组
int n,m;


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>primes[i];
    
    int ans=0;
    for(int i=1;i<(1<<m);i++)//遍历所有的状态
    {
        int t=1,cnt=0;//t代表此状态中所有元素的乘积，cnt代表状态中元素的个数
        for(int j=0;j<m;j++)
        {
            if(1<<j&i)//如果选择该元素
            {
                cnt++;//元素个数+1
                
                //乘积大于数据范围，直接进入下一种状态
                //注意：此处不开ll会造成数据溢出产生错误
                if((ll)primes[j]*t>n)
                {
                    t=-1;
                    break;
                }
                t*=primes[j];//否则计算乘积
            }
        }
        
        if(t!=-1)//当乘积在数据范围内
        {
            //容斥原理体现的地方
            //元素个数为奇数就+，为偶数就-
            if(cnt%2==1)ans+=n/t;
            else ans-=n/t;
        }
    }
    
    cout<<ans;//输出结果
    return 0;
}
