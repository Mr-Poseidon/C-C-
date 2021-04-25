#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=5010;

int primes[N],cnt;//��������
bool isp[N];//�Ƿ�������
int sum[N];//sum[i]ά����i���������ֵĴ���

void get_primes(int num)//��������ɸ
{
    for(int i=2;i<=num;i++)
    {
        if(!isp[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=num/i;j++)
        {
            isp[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}

int get(int num,int p)//����num!��������p���ֵĴ���
{
    int ans=0;
    while(num)
    {
        ans+=num/p;//����num!�к���������p�����ĸ���
        num/=p;
    }
    return ans;
}

vector<int> mul(vector<int> a,int b)//�������
{
    vector<int> c;
    
    for(int i=0,t=0;i<a.size()||t;i++)
    {
        if(i<a.size())t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    
    return c;
}

int main()
{
    int a,b;
    cin>>a>>b;
    
    get_primes(a);//ɸ����Χ�ڵ���������
    
    for(int i=0;i<cnt;i++)//�������������ӣ��������ڽ׳��и������ӳ��ֵĴ���
    {
        int p=primes[i];
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);//ͬһ�������ӣ������Ϊ���
    }
    
    vector<int> ans;
    ans.push_back(1);
    
    for(int i=0;i<cnt;i++)//����������
        for(int j=0;j<sum[i];j++)//���������ӳ��ֵĴ���
            ans=mul(ans,primes[i]);//������
            
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];//������
    
    return 0;
}
