#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int a[4]={10,20,50,100};//������ļ۸�

int f[N];//f[i]ά��Ǯ��Ϊiʱ�ɹ������ķ�����
int m;

int main()
{
    cin>>m;
    f[0]=1;//Ǯ��Ϊ0ʱ����Ҳ��һ�ַ���
    
    for(int i=0;i<4;i++)//�����������
        for(int j=a[i];j<=m;j++)//����Ǯ������ȫ�����Ż�����ǰ�������
            f[j]=f[j]+f[j-a[i]];//�������ķ������ܺ�
    
    cout<<f[m];
    return 0;
}
