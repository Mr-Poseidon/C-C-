#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;


//������ֵnum,���ֻ����һ�����ڵ���num��������
//�����ӣ�������������������
//ʱ�临�Ӷ�O(sqrt(n))
void divisor(int num)
{
    for(int i=2;i<=num/i;i++)//�������е���
        if(num%i==0)//���������
        {
            int sum=0;
            while(num%i==0)//���������ĸ���
            {
                num/=i;//����������������i
                sum++;
            }
            printf("%d %d\n",i,sum);//���
        }
    
    if(num>1)printf("%d %d\n",num,1);//����������һ������1�������ӣ����
    puts("");//����
}


int main()
{
    scanf("%d",&n);
    
    while(n--)
    {
        int t;
        scanf("%d",&t);
        divisor(t);
    }
    return 0;
}
