#include<iostream>
using namespace std;

const int N=110;

int a[N][N];
int n;

int main()
{
    while(cin>>n && n!=0)
    {
        for(int i=0;i<n;i++)//����ÿ����
        {
            int num=1;
            for(int j=i;j<n;j++)//������i�С���i��
                a[i][j]=a[j][i]=num++;//��ֵ
        }
        
        for(int i=0;i<n;i++)//���
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
