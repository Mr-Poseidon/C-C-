#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 插入排序
void insertion_sort(vector<int>& a)
{
    for(int i=0;i<a.size();i++)// 从第一个开始做插入
    {
        int t=a[i],j;// 存储数据
        for(j=i-1;j>=0;j--)// 从前一个数开始作比较
            if(t<a[j]) a[j+1]=a[j]; // 若前一个数比当前数大，则后一个数放前一个数
            else break;// 否则退出
        a[j+1]=t; // 后一个数放存储的数值，这个插入操作必须放在循环外面
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
    
    insertion_sort(a);
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
