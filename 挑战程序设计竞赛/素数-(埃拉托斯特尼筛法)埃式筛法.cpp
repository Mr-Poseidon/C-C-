#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long int ll;

int prime_sieve(int n)// O(n)
{
	vector<int> prime;
	vector<bool> is_prime(n+1,true);
	
	is_prime[0]=is_prime[1]=false;
	
	for(int i=2;i<=sqrt(n);i++)
		if(is_prime[i])
		{
			prime.push_back(i);
			for(int j=i*i;j<=n;j+=i)//ɸ�������������б��� 
				is_prime[j]=false;
		}
	return prime.size();
}

ll prime_segment_sieve(ll a,ll b)
{
	vector<ll> prime;//��ab������� 
	vector<bool> is_prime_sqrtb(sqrt(b)+1,true);//0~����b֮������� 
	vector<bool> is_prime_ab(b-a,true);//ab���������ƫ����Ϊa 
	
	for(ll i=2;i<sqrt(b);i++)
	{
		if(is_prime_sqrtb[i])
		{
			//ɸ 0~����b ��֦�������ظ� 
			for(ll j=i*2;j<sqrt(b);j+=i)is_prime_sqrtb[j]=false;
			// j= (a%i==0) ? a : (a/i*i+i) - jΪ>=a�ĵ�һ��i�ı��� 
			for(ll j=(a%i==0)?a:(a/i*i+i);j<b;j+=i)is_prime_ab[j-a]=false; 
		}
	}
	
	//���ab֮�������
	for(int i=0;i<is_prime_ab.size();i++)
		if(is_prime_ab[i])
			prime.push_back(i+a);
	return prime.size();
}

int main()
{
	int n;
	//cin>>n;
	//cout<<prime_sieve(n);
	cout<<prime_segment_sieve(22,37)<<endl;//3
	cout<<prime_segment_sieve(22801763489,22801787297)<<endl;//1000 
	return 0;
}
 
