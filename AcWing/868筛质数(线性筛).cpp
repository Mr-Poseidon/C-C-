#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1000010;

int prime[N],cnt;
bool isp[N];

/*
����ɸ֤���� 
	c1����ɸ���ĺ�����c2����ǰ���������������Ǻ�����Ҳ�������������ٶ����Ǻ���
	p(j)������С������
	�裺c1 = c2 * p(j)
	Ϊ�� c2 % p(j) == 0 �� c2��p(j)�ı���������ѭ��������
	���룺if(i%prime[j]==0)break;
	
	��������ѭ��ʱ������ c1 = p(j+1) * c2
	��������֪�� c2 % p(j) == 0 �裺c2 = p(j) * x 
	���ԣ� c1 =  p(j+1) * c2 = p(j+1) * p(j) * x
	c1Ӧ�ñ�p(j)ɸ��������Ӧ�ñ�p(j+1)ɸ����������������ظ�ɸ������� 
	�˴���c1���ں����������������ʱ�򡢱�p(j)ɸ��
	��֤��ÿ����ֻ�ᱻ����С��������ɸ�� 
*/ 

void get_prime(int n)
{
    for(int i=2;i<=n;i++)//�˴��������е���
    {
        if(!isp[i])prime[cnt++]=i;
        
        for(int j=0;prime[j]<=n/i;j++)//������������ 
        {
            isp[prime[j]*i]=true;
            //һ����i��һ����num����С�����ӡ���ôi������num�����б�������С������
            //prime[i]������i����С�����ӣ�����prime[i]ͬʱҲ����prime[j]*i����С������
            //�����뱾���ʣ����Բ������ѭ��Խ������ 
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    
    get_prime(n);
    
    printf("%d",cnt);
    
    return 0;
}
