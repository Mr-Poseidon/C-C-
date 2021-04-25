#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;//����ŷ�������ĺͱȽϴ󡢱����������
const int N=1000010;

int primes[N],cnt;
int phi[N];
bool isp[N];


ll get_eulers(int num)
{
    phi[1]=1;//1��ŷ������Ϊ1����Ϊ1�ͱ�����
    for(int i=2;i<=num;i++)//����2~N֮�����е���
    {
        if(!isp[i])//������
        {
            primes[cnt++]=i;//���
            phi[i]=i-1;//������ŷ������Ϊi-1
        }
        for(int j=0;primes[j]<=num/i;j++)//�������е�����
        {
            isp[ i * primes[j] ]=true;//ȥ����primes[j]Ϊ��С�����ӵĺ���
            
            if(i%primes[j]==0)//primes[j]��i����С�����ӡ��ص㡢����Ժ�������ظ�����
            {
                phi[ i * primes[j] ]=phi[i]*primes[j];
                break;//����ɸ�Ż� 
            }
            else phi[ i * primes[j] ]=phi[i]*(primes[j]-1);
        }
    }
    
    ll sum=0;//��������ŷ�������ĺ�
    for(int i=1;i<=num;i++)sum+=phi[i];
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<get_eulers(n)<<endl;//��ȡ1~N֮����������ŷ������֮��
    return 0;
}
