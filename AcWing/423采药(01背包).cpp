#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int f[N];//f[i]ά�����Ϊiʱ������װ������ֵ
int n,m;//n-��Ʒ������m-�������

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)//������Ʒ����
    {
        int v,w;
        cin>>v>>w;//���������Ȩֵ
        
        for(int j=m;j>=v;j--)//����01����
            f[j]=max(f[j],f[j-v]+w);
    }
    
    cout<<f[m];//������
    return 0;
}
