#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int v[N][N],w[N][N],s[N];//v[i][j]-��i���j����Ʒ�������v[i][j]-��i���j����Ʒ�ļ�ֵ��s[i]��i�����Ʒ����
int f[N];//f[i]ά�����Ϊiʱ������ֵ
int n,m;//n����Ʒ���������Ϊm


/*
    ע����������ȱ�������������ٱ���ÿһ���ÿ����Ʒ
*/
int main()
{
    cin>>n>>m;//����
    for(int i=1;i<=n;i++)//����i����Ʒ
    {
        cin>>s[i];//���뱾�����Ʒ����
        for(int j=0;j<s[i];j++)//ÿ����Ʒ������ͼ�ֵ
            cin>>v[i][j]>>w[i][j];
    }
    
    for(int i=1;i<=n;i++)//����ÿһ����Ʒ
        for(int j=m;j>0;j--)//�������
            for(int k=0;k<s[i];k++)//����������Ʒ�е�ÿ����Ʒ
                if(v[i][k]<=j)//����ѡ������
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);//״̬ת��
    
    cout<<f[m];//������ֵ
    return 0;
}
