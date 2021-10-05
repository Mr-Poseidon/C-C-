#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//选择排序
void selection_sort(vector<int>& a)
{
    for(int i=0;i<a.size();i++)// 选择第i个数
        for(int j=i+1;j<a.size();j++)// 和第j个数比较
            if(a[j]<a[i])// 若比第i个数小，交换两个数
                swap(a[i],a[j]);
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
    
    selection_sort(a);
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
