#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// ��������
void insertion_sort(vector<int>& a)
{
    for(int i=0;i<a.size();i++)// �ӵ�һ����ʼ������
    {
        int t=a[i],j;// �洢����
        for(j=i-1;j>=0;j--)// ��ǰһ������ʼ���Ƚ�
            if(t<a[j]) a[j+1]=a[j]; // ��ǰһ�����ȵ�ǰ�������һ������ǰһ����
            else break;// �����˳�
        a[j+1]=t; // ��һ�����Ŵ洢����ֵ�������������������ѭ������
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
