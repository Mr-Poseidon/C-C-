#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=510;

int a[N][N];//ά��������
int f[N][N];//ά��ÿһ������Ϊһ�������ζ�������ֵ
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//����������
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
            
    for(int i=n;i>=1;i--)//�ӵײ���ʼ����ת��
        for(int j=1;j<=i;j++)//�����ò��ÿһ����
            f[i][j]=max(f[i+1][j]+a[i][j],f[i+1][j+1]+a[i][j]);//���������� ���� ����������
    
    cout<<f[1][1];//������
    return 0;
}
