#include<iostream>
using namespace std;

const int N=110;

int a[N][N];
int n;

int main()
{
    while(cin>>n && n!=0)
    {
        for(int i=0;i<n;i++)//遍历每个角
        {
            int num=1;
            for(int j=i;j<n;j++)//遍历第i行、第i列
                a[i][j]=a[j][i]=num++;//赋值
        }
        
        for(int i=0;i<n;i++)//输出
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
