#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

//����¬��˹�������������ʱ�临�Ӷ�ΪO(PlogP)

int qmi(int a,int k,int p)//������
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return ans;
}

int C(int a,int b,int p)//�������������ʱ�临�Ӷ�O(n)
{
    int ans=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        ans=(ll)ans*j%p;
        ans=(ll)ans*qmi(i,p-2,p)%p;
    }
    return ans;
}

int lucas(ll a,ll b,ll p)//¬��˹����
{
    if(a<p && b<p)return C(a,b,p);
    else return (ll)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}

int main()
{
    int n;
    cin>>n;
    while(n--)//����
    {
        ll a,b,p;
        cin>>a>>b>>p;
        cout<<lucas(a,b,p)<<endl;
    }
    return 0;
}
