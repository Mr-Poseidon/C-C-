#include<iostream>
using namespace std;

long long int n,k,T,ans=1;//ans=1 - ������˵ 
long long int num=0,t=1;//tΪ����˵������ 

int main()
{
    cin>>n>>k>>T;
    
    for(int i=1;i<=n;i++)//n����ÿ����������ֵ�ܺ�%k�ǹ̶��� 
    {
    	num+=i;
    	num%=k;
    }
    
    for(int i=0;i<T-1;i++)//������˵������������ 
    {
    	// num+(i%k)*(n%k)*(n%k) - n�������������� 
    	// ԭʽ�� t += num + i*n*n; �������,����ȡģ 
    	t+=num+(i%k)*(n%k)*(n%k);
    	
    	t%=k;
    	
    	ans+=t;//tΪ���ζ����������� 
    }
    	
    cout<<ans;//������ 
    return 0;
}
