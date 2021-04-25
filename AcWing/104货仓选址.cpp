#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=100010;

int a[N];
int n;

int main()
{
    scanf("%d",&n);//输入
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    sort(a,a+n);//排序
    
    int avr;//求中位数
    if(n%2==0)avr=(a[n/2-1]+a[n/2])/2;
    else avr=a[n/2];
    
    int sum=0;//求距离之和
    for(int i=0;i<n;i++)
        sum+=abs(a[i]-avr);
    
    printf("%d",sum);//输出结果
    return 0;
}
