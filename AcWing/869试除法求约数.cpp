#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> get_divisor(int n)//�Գ���������Լ��
{
    vector<int> ans;
    for(int i=1;i<=n/i;i++)//��������С����sqrt(n)����
    {
        if(n%i==0)//��Լ��
        {
            ans.push_back(i);
            if(i!=n/i)ans.push_back(n/i);//��һ��Լ�������Լ����ͬ���������ƽ�������
        }
    }
    sort(ans.begin(),ans.end());//����
    return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int t;
        cin>>t;
        vector<int> ans=get_divisor(t);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";//�����
        cout<<endl;
    }
    return 0;
}
