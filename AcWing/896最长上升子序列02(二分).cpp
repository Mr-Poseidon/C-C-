#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1000010;

 
int n;
int a[N];

int main()
{
    scanf("%d",&n);//����
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    vector<int> q;//ģ���ջ
    q.push_back(a[0]);
    
    for(int i=1;i<n;i++)//����
        if(a[i]>q.back())q.push_back(a[i]);//�����ջβ�����ջ
        else *lower_bound(q.begin(),q.end(),a[i])=a[i];//����������Ӧ���滻
    
    printf("%d",q.size());//��󡢶�ջ�Ĵ�С��������������е�ֵ
    return 0;
}
