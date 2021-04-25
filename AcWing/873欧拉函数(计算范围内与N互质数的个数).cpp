#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

//���ڱ���ֻ��Ҫ�õ�������������Ҫ�õ��������Ĵ��ݡ�����û�п�unordered_map
int n;

/*
   ����1~N֮����N���ʵ����ĸ���
   ����gcd�ķ�����,����ÿһ�������ж��Ƿ���,�㷨���Ӷ�ΪO(N)
   ����ŷ���������㷨���Ӷ��Ż���O(sqrt(N))
*/

int main()
{
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        
        int ans=num;//�����ʼ����num
        
        for(int i=2;i<=num/i;i++)//�ֽ�������
        {
            if(num%i==0)
            {
                ans=ans/i*(i-1);//����ŷ���������ȳ��ٳ˿��Ա����������
                while(num%i==0)num/=i;//�ֽ�������
            }
        }
        if(num>1)ans=ans/num*(num-1);//���ڴ��ڵ���sqrt(num)��������
        
        cout<<ans<<endl;//���
    }
    return 0;
}
