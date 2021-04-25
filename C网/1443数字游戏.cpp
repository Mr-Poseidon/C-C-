#include<iostream>
using namespace std;

long long int n,k,T,ans=1;//ans=1 - 栋栋先说 
long long int num=0,t=1;//t为栋栋说的数字 

int main()
{
    cin>>n>>k>>T;
    
    for(int i=1;i<=n;i++)//n个人每轮所喊的数值总和%k是固定的 
    {
    	num+=i;
    	num%=k;
    }
    
    for(int i=0;i<T-1;i++)//栋栋先说，不包括在内 
    {
    	// num+(i%k)*(n%k)*(n%k) - n个人所递增的数 
    	// 原式： t += num + i*n*n; 避免溢出,挨个取模 
    	t+=num+(i%k)*(n%k)*(n%k);
    	
    	t%=k;
    	
    	ans+=t;//t为本次栋栋喊出的数 
    }
    	
    cout<<ans;//输出结果 
    return 0;
}
