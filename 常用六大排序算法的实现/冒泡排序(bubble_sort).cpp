#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;

// ð������ 
void bubble_sort(vector<int>& a)
{
    bool f=false;//������� 
    for(int i=a.size()-1;i>0;i--)//���ԱȽϵ����һ���� 
    {
        for(int j=0;j+1<=i;j++)//��0��ʼ���Ƚϵ����һ���� 
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                f=true;
            }
        if(f==false)return;//�����ڽ�����˵���Ѿ��ź����ˣ�ֱ�ӷ��أ�����һ��С�Ż� 
    }
}

int main()
{
    int n;
    cin>>n;// ���� 
    for(int i=0,t;i<n;i++)
    {
        cin>>t;
        a.push_back(t);
    }
    
    bubble_sort(a);
    
    // ��� 
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
