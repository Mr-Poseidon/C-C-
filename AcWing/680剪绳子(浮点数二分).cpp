#include<iostream>
#include<cstdio>
using namespace std;

const int N=100010;

int w[N];
int n,m;

bool check(double len)
{
    int cnt=0;//�����ܹ�����������
    for(int i=0;i<n;i++)
        cnt+=w[i]/len;
    
    return cnt>=m;//�ܹ����������� ���� Ҫ���������˵���������������Լ����ӳ�
}

int main()
{
    cin>>n>>m;//����
    for(int i=0;i<n;i++)cin>>w[i];
    
    double l=0,r=1e9;
    while(r-l>1e-4)//����������
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;//������ϣ��ͼӳ�
        else r=mid;//����ͱ��
    }
    
    printf("%.2lf",r);//������
    return 0;
}
