#include<iostream>
using namespace std;

typedef long long ll;

int qmi(int a,int k,int p)//�����ݺ���
{
    int ans=1;
    while(k)
    {
        //�˷�����������������Ҫ��long long
        if(k&1)ans=(ll)ans*a%p;//�η�����λΪ1,���ϸ�λ��a�η�
        k>>=1;//�η�λ����һλ
        a=(ll)a*a%p;//�����Գ˷���
    }
    return ans;//���ؽ��
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,k,p;
        scanf("%d%d%d",&a,&k,&p);//����
        printf("%d\n",qmi(a,k,p));//���������
    }
    return 0;
}
