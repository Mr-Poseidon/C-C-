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
        
        while(tt && stk[tt]>=x)tt--;//出栈
        
        if(tt)printf("%d ",stk[tt]);//不为空输出栈顶
        else printf("-1 ");//为空输出-1
        
        stk[++tt]=x;//入栈
    }
    return 0;
}
