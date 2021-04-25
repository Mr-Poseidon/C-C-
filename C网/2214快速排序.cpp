#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> ans;
    int t;
    while(cin>>t && t!=0)
        ans.push_back(t);
        
    sort(ans.begin(),ans.end());
    
    t=0;
    for(vector<int>::iterator it=ans.begin();it!=ans.end();it++)
    {
        if(t)cout<<" ";
        cout<<*it;
        t++;
    }
    return 0;
}
