#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void merge_sort(vector<int>& a,int l,int r)
{
    if(l>=r)return;//此处的=号可以解决边界问题
    
    int mid=(l+r)/2; // 去中间值
    merge_sort(a,l,mid);//递归
    merge_sort(a,mid+1,r);
    
    static vector<int> st;
    st.clear();
    int i=l,j=mid+1;
    while(i<=mid && j<=r)//归并
        if(a[i]<a[j])st.push_back(a[i++]);
        else st.push_back(a[j++]);
        
    //处理剩余元素
    while(i<=mid)st.push_back(a[i++]);
    while(j<=r)st.push_back(a[j++]);
    
    // 此处建议像如下一样，采用双指针的写法 
    for(i=0,j=l;i<st.size();i++,j++)a[j]=st[i];//覆盖
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
    
    merge_sort(a,0,a.size()-1);
    
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
