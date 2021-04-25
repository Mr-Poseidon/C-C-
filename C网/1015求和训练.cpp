#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int a,b,c;
double ans=0;

int main()
{
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
        ans+=i;
    for(int i=1;i<=b;i++)
        ans+=pow(i,2);
    for(int i=1;i<=c;i++)
        ans+=1.0/i;
    printf("%.2lf",ans);
    return 0;
}
