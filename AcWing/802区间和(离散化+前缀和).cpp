#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//因为添加会出现1e5个坐标，查询会出现2e5个坐标，总共3e5个
const int N=300010;
//a[N]用来存原始数组，s[N]维护前缀和
int a[N],s[N];

int n,m;
//add存添加操作，query存查询操作
vector<pair<int,int>> add,query;
//alls维护坐标离散化
vector<int> alls;


int find(int x)//查找离散化后的坐标
{
    //因为维护区间和，所以坐标+1
    return lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1;
}
int main()
{
    cin>>n>>m;//输入
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});//存添加操作
        
        alls.push_back(x);//存坐标
    }
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        query.push_back({a,b});//存查询操作
        
        //存坐标
        alls.push_back(a);
        alls.push_back(b);
    }
    
    sort(alls.begin(),alls.end());//排序
    alls.erase(unique(alls.begin(),alls.end()),alls.end());//去重
    
    for(vector<pair<int,int>>::iterator it=add.begin();it!=add.end();it++)//添加操作
    {
        int p=find((*it).first);
        a[p]+=(*it).second;
    }
    
    //维护前缀和
    int si=alls.size();
    for(int i=1;i <= si;i++) s[i]=s[i-1]+a[i];
    
    for(vector<pair<int,int>>::iterator it=query.begin();it!=query.end();it++)//查询操作
    {
        int a=find((*it).first),b=find((*it).second);
        cout<<s[b]-s[a-1]<<endl;
    }
    return 0;
}
