#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> ans;//存合并后的区间
    
    sort(segs.begin(),segs.end());//排序、pair排序默认先first,再second,从小到大
    
    int st=-2e9,ed=-2e9;//初始区间
    for(vector<PII>::iterator it=segs.begin();it!=segs.end();it++)
    {
        if(ed < (*it).first)//如果新区间的左端点大于旧区间的右端点、说明不相交
        {
            if(st!=-2e9)ans.push_back({st,ed});//原始区间不记录
            st=(*it).first,ed=(*it).second;//更新
        }
        else ed=max(ed,(*it).second);//相交或包含、更新右端点
    }
    
    if(st!=-2e9)ans.push_back({st,ed});//判断最后一个区间、也可以避免空区间
    
    segs=ans;//覆盖
}

int main()
{
    cin>>n;//输入
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    
    merge(segs);//合并区间
    
    cout<<segs.size()<<endl;
    return 0;
}

