#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll n,k,m;

mat mul(mat a,mat b)//����˷� 
{
	mat ans(n,vec(n,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%m;
	return ans;
}

mat pow(mat a,ll b)//��������� 
{
	mat ans(n,vec(n,0));
	for(int i=0;i<n;i++)
		ans[i][i]=1;
	
	while(b)
	{
		if(b&1)
			ans=mul(ans,a);
		b>>=1;
		a=mul(a,a);
	}
	return ans;
}

mat add(mat a,mat b)//����ӷ� 
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=(a[i][j]+b[i][j])%m;
	return a;	
}

/*
A + A^2 =A(I+A)

A  + A^2 + A^3 + A^4 = (A + A^2)(I + A^2)
����sum(n) = A  +A^2 +A^3 +...+A^n
���n��ż��  sum(n) = sum(n/2)(I+A^(n/2))
���n������  sum(n) = sum(n-1) + A^n
            = sum((n-1)/2)(I+A^((n-1)/2)) + A^n
*/

mat sum(mat a,int k)//����ͺ��� 
{
	if(k==1)return a;//�ݹ���� 
	
	mat ans(n,vec(n,0));
	for(int i=0;i<n;i++)
		ans[i][i]=1;
		
	ans=add(ans,pow(a,k>>1));// �� 1 + a^(k/2)�� 
	ans=mul(ans,sum(a,k>>1));// �� sum( a^(k/2) )�� 
	if(k&1)//�ж�k�Ƿ�Ϊ���� 
		ans=add(ans,pow(a,k));
		
	return ans;
}

int main()
{
	cin>>n>>k>>m;
	
	mat s(n,vec(n,0));
	mat a(n,vec(n,0));
	
	for(int i=0;i<n;i++)//������� 
		for(int j=0;j<n;j++)
			cin>>a[i][j];
			
	s=sum(a,k);//����� 
	
	for(int i=0;i<n;i++)//��� 
	{
		for(int j=0;j<n;j++)
		{
			if(j)
				cout<<" ";
			cout<<s[i][j]; 
		}
		cout<<endl;
	}
	return 0;	 
}
