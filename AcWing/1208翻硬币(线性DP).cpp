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
    cin>>s>>p;//���������ַ���
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=p[i])
        {
            change(i);//�任
            change(i+1);
            ans++;//����+1
        }
        
    cout<<ans;//������
    return 0;
}
