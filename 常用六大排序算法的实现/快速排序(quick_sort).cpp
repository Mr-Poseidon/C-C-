#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 快速排序
void quick_sort(vector<int>& a,int l,int r)
{
    if(l>=r)return;
    
    int i=l-1,j=r+1,x=a[(l+r)>>1];//x可以是一个随机数，此处选择中间的数
    while(i<j)
    {
        do i++;while(a[i]<x);//此处是一个双指针
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);//交换
        else quick_sort(a,l,j),quick_sort(a,j+1,r);//递归,此处参数必须是 j
    }
}

int main()
{
    int n;
    vector<int> a;
    
    cin>>n;
    for(int i=0,t;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    
    quick_sort(a,0,a.size()-1);
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
