#include<iostream>
#include<algorithm>
using namespace std;

const int N=20010;

//�����е���Ʒ���������������Ǽ�ֵ

int f[N];//ά��01����
int n,m;

int main()
{
    cin>>m>>n;//�����������Ʒ����
    
    for(int i=0;i<n;i++)//������Ʒ����
    {
        int v;
        cin>>v;//�������
        
        for(int j=m;j>=v;j--)//ά��01���������ֵ
            f[j]=max(f[j],f[j-v]+v);
    }
    
    cout<<m-f[m];//�����С��ʣ��ռ�
    return 0;
}
