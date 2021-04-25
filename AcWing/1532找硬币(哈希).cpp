#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=200003,INF=0x3f3f3f3f;

int h[N];
int a[N];
int n,m;

int find(int num)//����Ѱַ����ϣ
{
    int k=(num%N+N)%N;

    while(h[k]!=INF && h[k]!=num)
    {
        k++;
        if(k==N)k=0;
    }

    return k;
}

int main()
{
    cin>>n>>m;//����
    for(int i=0;i<n;i++)cin>>a[i];

    sort(a,a+n);//����

    memset(h,0x3f,sizeof h);//��ʼ����ϣ��
    for(int i=0;i<n;i++)h[find(a[i])]=a[i];//��ϣ

    for(int i=0;i<n;i++)//����
    {
        int j=find(a[i]);
        int k=find(m-a[i]);

        if(h[k]==m-a[i] && j!=k)//j!=k��ʾ�����������ڡ�ͬ������ֵҲҪ��������
        {
            cout<<a[i]<<" "<<m-a[i];
            return 0;
        }
    }


    cout<<"No Solution";
    return 0;       
}
