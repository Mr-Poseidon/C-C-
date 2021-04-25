#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=35;//2e9的二进制有32位、取35避免越界 

int f[N][N];//f[i][j]维护从i个数里面选择j个数为1的情况
int l,r,K,B;

void init()//预处理，组合数
{
    //从i个数位里面选择j个数位为1
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            if(!j)f[i][j]=1;//一个都不选也是一种情况
            else f[i][j]=f[i-1][j-1]+f[i-1][j];//针对元素1而言，第i个选择了1，就是再从i-1个数里选择j-1个1，即f[i-1][j-1]
                                               //               第i个没有选择1，则从i-1个数里选择j个1，即f[i-1][j]
}
//dp(n)返回[0,n]这个区间中存在的所有合法方案
int dp(int n)
{
    if(n==0)return 0;//边界特判、0这个数中一个合法方案都没有
    
    vector<int> nums;//将每一位数存起来
    while(n)nums.push_back(n%B),n/=B;//转化成B进制数
    
    int ans=0;//维护合法方案
    int pre=0;//之前的选择的1的个数，刚开始一个都没有选
    for(int i=nums.size()-1;i>=0;i--)//遍历每一位数
    {
        int x=nums[i];//第i位数字
        
        if(x!=0)//x！=0,说明本位可以选择[0,x]
        {
            ans+=f[i][K-pre];//本位选0，从剩下的i=n-1位中选择K-pre个1
            if(x>1)
            {
                if(K-pre-1>=0)ans+=f[i][K-pre-1];//在x>1时，本位选1的情况
                break;//因为只能出现0和1，本位x>1不合法、直接跳出循环
            }
            else//本位刚好为1
            {
                pre++;
                if(pre>K)break;//超出要选择的数量、跳出循环
            }
        }
        
        
        if(i==0 && pre==K)ans++;//遍历到最后一位，并且前面刚好选了K个1，本次不选1是最后一种情况，所以++
    }
    
    return ans;//返回结果
}

int main()
{
    init();//预处理
    
    cin>>l>>r>>K>>B;//输入
    
    cout<<dp(r)-dp(l-1)<<endl;//输出
    return 0;
}
