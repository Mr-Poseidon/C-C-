#include<iostream>
using namespace std;

const int N=10010;

int f[N];//ά��������飬ǰ׺��
int n,m;

int main()
{
    cin>>n>>m;
    
    //��Ϊά��ǰ׺�͡��������������һλ��1����0��
    f[0+1]=1;//��ʼ��
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        
        //����
        f[a+1]--;//����Լ�
        f[b+1+1]++;//�յ�ĺ�һλ�Լ�
    }
    
    int ans=0;//��¼��
    for(int i=1;i<=n+1;i++)
    {
        f[i]+=f[i-1];//��һ��ǰ׺��
        if(f[i]>0)ans++;//�������0��������
    }
    
    cout<<ans;//������
    return 0;
}
