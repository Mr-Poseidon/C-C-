#include<iostream>
#include<algorithm>
using namespace std;

const int mod=1e9+7;
typedef long long ll;

//�����������ó����쿨������
//����������ʽ��C(2n,n)-C(2n,n-1) = 1/(n+1)*C(2n,n)

int qmi(int a,int k,int p)//������
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        k>>=1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    
    int ans=1;
    for(int i=1,j=2*n;i<=n;i++,j--)//���ݶ����������
    {
        ans=(ll)ans*j%mod;
        ans=(ll)ans*qmi(i,mod-2,mod)%mod;
    }
    
    ans=(ll)ans*qmi(n+1,mod-2,mod)%mod;//����ϵ��1/(n+1)����(n+1)����Ԫ��ͬģ����Ԫ
    
    cout<<ans;//�����
    return 0;
}
