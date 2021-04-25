#include<iostream>
#include<algorithm>
using namespace std;

const int M=6010;

int f[M];
int n,m;

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++)//������Ʒ����
    {
        int v,w,s;//����
        cin>>v>>w>>s;
        
        for(int j=m;j>=v;j--)//�������
            for(int k=1;k<=s && k*v<=j ;k++)//������Ʒ����
                f[j]=max(f[j],f[j-k*v]+k*w);
    }
    cout<<f[m];//���
    return 0;
}

