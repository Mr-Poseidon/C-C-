#include<iostream>
#include<algorithm>
using namespace std;


/*
    ��һ�������൱�ڳ���һ��������Ԫ
    ����ģ��Ϊ���������ݷ���С�������ÿ�������num����ԪΪ��qmi(num,mod-2,mod);
*/
typedef long long ll;
const int N=100010,mod=1e9+7;

int fact[N],infact[N];//fact[]ά��һ�����Ľ׳ˣ�infact[]ά��һ��������Ԫ�ײ� 

int qmi(int a,int k,int p)//������ 
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(ll)ans*a%p;
        k>>=1;
        a=(ll)a*a%p;
    }
    return ans;
}


void init()//��ʼ�� 
{
    fact[0]=infact[0]=1;//0�Ľײ����Ԫ�ײ㶼Ϊ 1 
    for(int i=1;i<N;i++)
    {
        fact[i]=(ll)fact[i-1]*i%mod;
        //�����Ԫ��Ҫ����ǰһ��������Ԫ�׳�Ȼ����ȡģ
        infact[i]=(ll)infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
}
int main()
{
    init();
    
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        //���ݽ׳˹�ʽc(a,b)=a!/(b!*(a-b)!),��һ�������ǳ���һ��������Ԫ
        cout<<(ll)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}
