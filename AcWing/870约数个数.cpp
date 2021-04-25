#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

typedef long long int ll;//����ȡģ�����붨��ll�������������
const int mod=1e9+7;

unordered_map<int,int> primes;//�������ά���������Ĵη�
int n;

int main()
{
    
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        for(int i=2;i<=num/i;i++)//��ÿ�����ֽ�������
            while(num%i==0)
            {
                num/=i;//�Գ�
                primes[i]++;//�η�+1
            }
        if(num>1)primes[num]++;//����������һ������sqrt(num)������������¼
    }
    
    ll ans=1;
    for(unordered_map<int,int>::iterator it=primes.begin();it!=primes.end();it++)//��������������
        ans=ans*(it->second+1)%mod;//����Լ���ĸ����������������Ĵη�+1���
    
    cout<<ans;//������
    return 0;
}
