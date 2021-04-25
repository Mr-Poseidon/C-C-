#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;

queue<string> q;//���� 
map<string,int> v,step;//v-�ж��Ƿ���ʹ���step-��Ų��� 

void bfs(string start,string end)//���� 
{
	v[start]=1;//��� 
	step[start]=0;
	q.push(start);
	
	while(!q.empty())
	{
		string s=q.front();
		q.pop();
		
		if(s==end)return;//����Ŀ�� 
			
		
		for(int i=0;i<s.size();i+=4)//ÿ��ǰ���� 
			for(int j=0;j<3;j++)
			{
				string ts=s;
				swap(ts[i+j],ts[i+j+1]);//���ҽ��� 
				if(v.find(ts)==v.end())//ts������ 
				{
					v[ts]=1;
					step[ts]=step[s]+1;
					q.push(ts);
				}
			}
		
		for(int i=0;i<4;i++)//ÿ��ǰ���� 
			for(int j=0;j<12;j+=4)
			{
				string ts=s;
				swap(ts[i+j],ts[i+j+4]);//���½��� 
				if(v.find(ts)==v.end())//ts������ 
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
