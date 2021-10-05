#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// ��������
void quick_sort(vector<int>& a,int l,int r)
{
    if(l>=r)return;
    
    int i=l-1,j=r+1,x=a[(l+r)>>1];//x������һ����������˴�ѡ���м����
    while(i<j)
    {
        do i++;while(a[i]<x);//�˴���һ��˫ָ��
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);//����
        else quick_sort(a,l,j),quick_sort(a,j+1,r);//�ݹ�,�˴����������� j
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
