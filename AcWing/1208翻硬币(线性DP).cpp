#include<iostream>
#include<cstring>
using namespace std;

const int N=110;

char s[N],p[N];
int a[N],b[N];
int ans;

void change(int k)
{
    if(p[k]=='*')p[k]='o';
    else p[k]='*';
    return;
}

int main()
{
    cin>>s>>p;//输入两个字符串
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=p[i])
        {
            change(i);//变换
            change(i+1);
            ans++;//次数+1
        }
        
    cout<<ans;//输出结果
    return 0;
}
