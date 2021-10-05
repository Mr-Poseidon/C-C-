#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;

// 冒泡排序 
void bubble_sort(vector<int>& a)
{
    bool f=false;//交换标记 
    for(int i=a.size()-1;i>0;i--)//可以比较的最后一个数 
    {
        for(int j=0;j+1<=i;j++)//从0开始，比较到最后一个数 
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                f=true;
            }
        if(f==false)return;//不存在交换，说明已经排好序了，直接返回，这是一个小优化 
    }
}

int main()
{
    int n;
    cin>>n;// 输入 
    for(int i=0,t;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    
    bubble_sort(a);
    
    // 输出 
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
