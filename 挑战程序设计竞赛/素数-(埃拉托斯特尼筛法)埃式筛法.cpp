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
			for(int j=i*i;j<=n;j+=i)//筛掉该素数的所有倍数 
				is_prime[j]=false;
		}
	return prime.size();
}

ll prime_segment_sieve(ll a,ll b)
{
	vector<ll> prime;//存ab间的素数 
	vector<bool> is_prime_sqrtb(sqrt(b)+1,true);//0~根号b之间的素数 
	vector<bool> is_prime_ab(b-a,true);//ab间的素数，偏移量为a 
	
	for(ll i=2;i<sqrt(b);i++)
	{
		if(is_prime_sqrtb[i])
		{
			//筛 0~根号b 剪枝，避免重复 
			for(ll j=i*2;j<sqrt(b);j+=i)is_prime_sqrtb[j]=false;
			// j= (a%i==0) ? a : (a/i*i+i) - j为>=a的第一个i的倍数 
			for(ll j=(a%i==0)?a:(a/i*i+i);j<b;j+=i)is_prime_ab[j-a]=false; 
		}
	}
	
	//求出ab之间的素数
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
 
