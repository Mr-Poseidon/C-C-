#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//ѡ������
void selection_sort(vector<int>& a)
{
    for(int i=0;i<a.size();i++)// ѡ���i����
        for(int j=i+1;j<a.size();j++)// �͵�j�����Ƚ�
            if(a[j]<a[i])// ���ȵ�i����С������������
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
