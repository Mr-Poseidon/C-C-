#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;

queue<string> q;//队列 
map<string,int> v,step;//v-判断是否访问过，step-存放步数 

void bfs(string start,string end)//深搜 
{
	v[start]=1;//起点 
	step[start]=0;
	q.push(start);
	
	while(!q.empty())
	{
		string s=q.front();
		q.pop();
		
		if(s==end)return;//到达目标 
			
		
		for(int i=0;i<s.size();i+=4)//每行前三列 
			for(int j=0;j<3;j++)
			{
				string ts=s;
				swap(ts[i+j],ts[i+j+1]);//向右交换 
				if(v.find(ts)==v.end())//ts不存在 
				{
					v[ts]=1;
					step[ts]=step[s]+1;
					q.push(ts);
				}
			}
		
		for(int i=0;i<4;i++)//每列前三行 
			for(int j=0;j<12;j+=4)
			{
				string ts=s;
				swap(ts[i+j],ts[i+j+4]);//向下交换 
				if(v.find(ts)==v.end())//ts不存在 
				{
					v[ts]=1;
					step[ts]=step[s]+1;
					q.push(ts);
				}
			}
	}
}

int main()
{
	string start,end;
	for(int i=0;i<4;i++)
	{
		string t;
		cin>>t;
		start.append(t);
	} 
	for(int i=0;i<4;i++)
	{
		string t;
		cin>>t;
		end.append(t);
	}
	
	bfs(start,end);
	
	cout<<step[end]<<endl;
	
	return 0;
}
