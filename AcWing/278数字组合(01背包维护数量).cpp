#include<iostream>
#include<algorithm>
using namespace std;

const int N=10010;

int f[N];//f[i]ά����Ϊiʱ�ķ�����
int n,m;

int main()
{
    cin>>n>>m;
    f[0]=1;//��Ϊ0ʱ����ѡҲ��һ�ַ���
    
    for(int i=0;i<n;i++)//�������ĸ���
    {
        int v;
        cin>>v;
        for(int j=m;j>=v;j--)
            f[j]=f[j]+f[j-v];//ѡ�Ͳ�ѡ�ķ������ܺ�
    }
    cout<<f[m];//���
    return 0;
}
