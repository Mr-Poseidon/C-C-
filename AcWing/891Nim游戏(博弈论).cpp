#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    int ans=0;//�������Ľ��
    while(n--)
    {
        int t;
        scanf("%d",&t);
        ans^=t;//����ֵ���
    }
    if(ans!=0)cout<<"Yes";//������ֵ���Ľ����Ϊ�㣬˵����ʤ
    else cout<<"No";//�������ֱذ�
    
    return 0;
}
