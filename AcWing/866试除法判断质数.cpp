#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int n;

bool isprime(int n)//�ж�����
{
    if(n<2)return false;
    for(int i=2;i<=n/i;i++)//ע��˴�д��:i<=n/i,��������������
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        if(isprime(t))puts("Yes");
        else puts("No");
    }
    return 0;
}
