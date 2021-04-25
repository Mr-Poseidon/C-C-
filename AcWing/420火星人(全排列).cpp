#include<iostream>
#include<algorithm>
using namespace std;

const int N=10010;

int n,m;
int num[N];

int main()
{
    cin>>n>>m;//输入
    for(int i=0;i<n;i++)cin>>num[i];
    
    for(int i=0;i<m;i++)next_permutation(num,num+n);//排列m次
    
    for(int i=0;i<n;i++)cout<<num[i]<<" ";//输出
    return 0;
}
