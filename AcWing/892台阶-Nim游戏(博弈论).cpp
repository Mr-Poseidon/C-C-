#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(i%2)ans^=t;//����̨������������൱�����һ��
        else continue;//ż��̨�����ż����Ϊ0
    }
    if(ans!=0)cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
