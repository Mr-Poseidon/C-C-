/*����һ 
#include<iostream>
#include<vector>
using namespace std;

vector<int> g[10000];
/*
//��Ȩ�ڽӱ� 
struct edge
{
	int to,cost;
};
vector<edge> g[100000];


int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int s,t;
		cin>>s>>t;
		g[s].push_back(t);//sָ��t
		g[t].push_back(s);//����ͼ 
	}
	
	for(int i=0;i<v;i++)//��� 
	{
		for(vector<int>::iterator it=g[i].begin();it!=g[i].end();it++)
		{
			if(it!=g[i].begin())cout<<" ";
			cout<<*it;
		}
		cout<<endl;
	}
	return 0; 
}
*/


#include<iostream>
#include<vector>
using namespace std;

struct vertex
{
	vector<vertex*> edge;
	/*
	 * ��������� 
	 */	
};
vertex g[10000];

int main()
{
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int s,t;
		cin>>s>>t;
		g[s].edge.push_back(&g[t]);
		//g[t].edge.push_back(&g[s]);//����ͼ 
	}
	/*
		ͼ�Ĳ��� 
	*/
	return 0; 
} 
