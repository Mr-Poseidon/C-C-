#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int n,m;
char a[N],b[N];//ά�������ַ���
int f[N][N];//f[i][j]��ʾ a��ǰi���ַ��� �� b��ǰj���ַ��� �������������

int main()
{
    //���룬���ڴ���i-1,j-1,�����ַ����±���1��ʼ
    cin>>n>>m>>a+1>>b+1;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            //f[i][j]���������������ѡai����ѡai��*(ѡbj����ѡbj)
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
        
    cout<<f[n][m];//���
    return 0;
}
