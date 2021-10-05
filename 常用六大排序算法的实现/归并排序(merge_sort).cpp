#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void merge_sort(vector<int>& a,int l,int r)
{
    if(l>=r)return;//�˴���=�ſ��Խ���߽�����
    
    int mid=(l+r)/2; // ȥ�м�ֵ
    merge_sort(a,l,mid);//�ݹ�
    merge_sort(a,mid+1,r);
    
    static vector<int> st;
    st.clear();
    int i=l,j=mid+1;
    while(i<=mid && j<=r)//�鲢
        if(a[i]<a[j])st.push_back(a[i++]);
        else st.push_back(a[j++]);
        
    //����ʣ��Ԫ��
    while(i<=mid)st.push_back(a[i++]);
    while(j<=r)st.push_back(a[j++]);
    
    // �˴�����������һ��������˫ָ���д�� 
    for(i=0,j=l;i<st.size();i++,j++)a[j]=st[i];//����
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
