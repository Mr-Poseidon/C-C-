#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1000010;

bool isp[N];//ά���ǲ���������Ĭ�϶�������
int prime[N],cnt;//prime[]ά���������У�cnt���������ĸ���
int n;


void get_prime(int num)
{
    for(int i=2;i<=num;i++)//������������
        if(!isp[i])//������
        {
            prime[cnt++]=i;//���
            for(int j=i+i;j<=n;j+=i)isp[j]=true;//ȥ���������еı���
        }
}


int main()
{
    scanf("%d",&n);
    
    get_prime(n);
    
    printf("%d",cnt);
    
    return 0;
}

