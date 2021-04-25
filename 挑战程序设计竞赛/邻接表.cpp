/*样例一 
#include<iostream>
#include<vector>
using namespace std;

vector<int> g[10000];
/*
//带权邻接表 
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
		g[s].push_back(t);//s指向t
		g[t].push_back(s);//无向图 
	}
	
	for(int i=0;i<v;i++)//输出 
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
	 * 顶点的属性 
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
		//g[t].edge.push_back(&g[s]);//无向图 
	}
	/*
		图的操作 
	*/
	return 0; 
} 
