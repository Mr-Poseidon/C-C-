#include<iostream>
#include<algorithm>
using namespace std;

const int N=10010;

int n,m;
int num[N];

int main()
{
    cin>>n>>m;//����
    for(int i=0;i<n;i++)cin>>num[i];
    
    for(int i=0;i<m;i++)next_permutation(num,num+n);//����m��
    
    for(int i=0;i<n;i++)cout<<num[i]<<" ";//���
    return 0;
}
