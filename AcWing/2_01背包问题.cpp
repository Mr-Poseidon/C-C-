#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

int f[N];//�Ż���һά
int v[N],w[N];//v[i],w[i]ά����Ʒ������ͼ�ֵ
int n,m;//��Ʒ��������������


int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)//����ÿ�θ�����Ҫ�õ�ǰ������ݡ����ԴӺ���ǰ����
            f[j]=max(f[j],f[j-v[i]]+w[i]);//״̬ת�Ʒ���
    
    cout<<f[m]<<endl;
    return 0;
}
