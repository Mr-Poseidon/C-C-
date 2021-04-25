#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1000010;

 
int n;
int a[N];

int main()
{
    scanf("%d",&n);//输入
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    vector<int> q;//模拟堆栈
    q.push_back(a[0]);
    
    for(int i=1;i<n;i++)//遍历
        if(a[i]>q.back())q.push_back(a[i]);//如果比栈尾大就入栈
        else *lower_bound(q.begin(),q.end(),a[i])=a[i];//否则做出相应的替换
    
    printf("%d",q.size());//最后、堆栈的大小就是最长上升子序列的值
    return 0;
}
