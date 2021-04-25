#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int h[N],sizes;

void down(int k)//���µݹ�
{
    int t=k;
    if(k*2<=sizes && h[k*2]<h[t])t=k*2;//�ж��������Ƿ�С�ڸ�
    if(k*2+1<=sizes && h[k*2+1]<h[t])t=k*2+1;//�ж��������Ƿ�С�ڸ���������
    if(t!=k)//����С�����
    {
        swap(h[k],h[t]);//����
        down(t);//�ݹ�
    }
}

void up(int k)//���ϱ���
{
    while(k/2>=0 && h[k/2]>h[k])
    {
        swap(h[k/2],h[k]);
        k/=2;
    }
}

void erase(int k)//ɾ������
{
    h[k]=h[sizes];//���ѵ׻���ɾ����λ��
    sizes--;//������--
    down(k);//�Ӹ�λ�����µݹ�
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    //�����
    for(int i=1;i<=n;i++)cin>>h[i];//������Ԫ����������ģ��Ķ���
    sizes=n;//��������ֵ
    
    //ʱ�临�Ӷ�O(N)
    for(int i=n/2;i;i--)down(i);//�Գ�ʼ��
    
    while(m--)//ɾ������
    {
        cout<<h[1]<<" ";
        erase(1);
    }
    return 0;
}
