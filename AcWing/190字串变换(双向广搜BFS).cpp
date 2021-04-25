#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<queue>
using namespace std;

const int N=6;

string A,B;
string a[N],b[N];
int n=0;

//由于本题两个端点的扩展方式有顺序前后之分、所以要分别维护两个端点的各自的队列状态、并且写一个扩展函数

unordered_map<string,int> da,db;//维护a，b队列中元素的距离
queue<string> qa,qb;//维护a，b队列

//扩展，q代表要搜索的队列，da，db代表两个队列中元素的距离，a状态 转换成 b状态
int extend(queue<string>& q,unordered_map<string,int>& da,unordered_map<string,int>& db,string a[],string b[])
{
    string ts=q.front();//取出队头
    q.pop();
    
    for(int i=0;i<n;i++)//遍历变换规则
        for(int j=0;j<(int)ts.size();j++)//遍历起点
            if(ts.substr(j,(int)a[i].size())==a[i])//可以进行变换
            {
                string nst=ts.substr(0,j)+b[i]+ts.substr(j+a[i].size());//获取新的状态
                
                if(db.count(nst))return da[ts]+db[nst]+1;//新状态出现在另一个队列中，返回步数
                
                if(da.count(nst))continue;//若新状态在本队列中出现过、跳过
                q.push(nst);//入队
                da[nst]=da[ts]+1;//距离+1
            }
    return 11;//返回11即表示无法到达
}
int bfs()
{
    //两个队头入队 并 标记步数为0
    qa.push(A),da[A]=0;
    qb.push(B),db[B]=0;
    
    //只有两个队列都存在才有可能到达、若其中一个队列没有搜到并且队列为空、说明这个区域是个闭环
    while(qa.size() && qb.size())
    {
        int step=0;
        if(qa.size()<=qb.size())step=extend(qa,da,db,a,b);//优化搜索顺序、从种类较少的队列开始扩展
        else step=extend(qb,db,da,b,a);
        
        if(step<=10)return step;//出现最短距离
    }
    return 11;
}


int main()
{
    cin>>A>>B;//输入
    while(cin>>a[n]>>b[n])n++;
    
    int step=bfs();//双向广搜
    
    if(step<=10)cout<<step<<endl;//输出
    else puts("NO ANSWER!");
    
    return 0;
}
