#include<cstdio>
#include<iostream>
using namespace std;

int stk[100010],tt;

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        
        while(tt && stk[tt]>=x)tt--;//��ջ
        
        if(tt)printf("%d ",stk[tt]);//��Ϊ�����ջ��
        else printf("-1 ");//Ϊ�����-1
        
        stk[++tt]=x;//��ջ
    }
    return 0;
}
