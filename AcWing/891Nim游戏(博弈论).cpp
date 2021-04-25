#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    int ans=0;//代表异或的结果
    while(n--)
    {
        int t;
        scanf("%d",&t);
        ans^=t;//与数值异或
    }
    if(ans!=0)cout<<"Yes";//所有数值异或的结果不为零，说明必胜
    else cout<<"No";//否则先手必败
    
    return 0;
}
