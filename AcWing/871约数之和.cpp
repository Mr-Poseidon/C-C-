#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n;
unordered_map<int,int> primes;//ά��������

int main()
{
    cin>>n;
    while(n--)//�ֽ��������������
    {
        int num;
        cin>>num;
        for(int i=2;i<=num/i;i++)//����������
            while(num%i==0)
            {
                num/=i;//ȥ��һ��������
                primes[i]++;//�����ӵĴ���+1
            }
        if(num>1)primes[num]++;//���ڴ��ڵ���sqrt(num)��������
    }
    
    ll ans=1;
    for(unordered_map<int,int>::iterator it=primes.begin();it!=primes.end();it++)//�������е�������
    {
        int p=it->first,a=it->second;//p���������a����ָ��
        ll sum=1;
        while(a--)sum=(sum*p+1)%mod;//������pΪ�ף�0~a���ݵĺ�
        ans=(ans*sum)%mod;//�������������Ӻ͵ĳ˻�
    }
    cout<<ans;
    return 0;
}
