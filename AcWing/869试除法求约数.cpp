#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> get_divisor(int n)//试除法求所有约数
{
    vector<int> ans;
    for(int i=1;i<=n/i;i++)//遍历所有小等于sqrt(n)的数
    {
        if(n%i==0)//是约数
        {
            ans.push_back(i);
            if(i!=n/i)ans.push_back(n/i);//另一个约数与这个约数不同、避免出现平方的情况
        }
    }
    sort(ans.begin(),ans.end());//排序
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
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";//输出答案
        cout<<endl;
    }
    return 0;
}
