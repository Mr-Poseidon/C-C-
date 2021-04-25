#include<iostream>
using namespace std;

int n,map[25];//map[]-记录图 

int dfs(int stairs)
{
	if(stairs==0)return 1;//到达 
	if(stairs<0)return 0;//超过 
	if(map[stairs]!=-1)return map[stairs];//直接返回曾经的情况 
	
	return map[stairs]=dfs(stairs-1)+dfs(stairs-3);//注意此处 
}

int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)//重置记忆图 
		map[i]=-1;
	cout<<dfs(n)<<endl;//输出结果 
	return 0;
}
