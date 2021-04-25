#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n;
int v[1005][1005];
int map[1005][1005];
int peak=0,valley=0;
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};//八个方向 

struct Point{
	int x,y;
}point;


void bfs(int x,int y)
{
	bool is_peak=true,is_valley=true;//判断该块是山峰还是山谷 
	
	if(v[x][y]==1)return;//访问过，跳过 
	queue<Point> block;//块队列 
	
	v[x][y]=1;//标记 
	
	Point p;//起点入队 
	p.x=x;
	p.y=y;
	block.push(p);
	
	while(!block.empty())
	{
		Point p=block.front();
		block.pop();
		
		
		for(int i=0;i<8;i++)//遍历周围八个方向 
		{
			int x=p.x+dir[i][0];
			int y=p.y+dir[i][1];
			if(x>=0 && x<n && y>=0 && y<n)//未越界 
			{
				if(map[x][y]==map[p.x][p.y])//相等为块 
				{
					if(v[x][y]==0)//未访问 
					{
						Point t;
						t.x=x;
						t.y=y;
						block.push(t);
						v[x][y]=1;//标记 
						continue;
					}	
				}
				else//不等为边 
				{
					if(map[x][y]>map[p.x][p.y])is_peak=false;//边比较高 
					if(map[x][y]<map[p.x][p.y])is_valley=false;//边比较低 
					continue;
				}
			}
		}
	}
	if(is_peak)peak++;
	if(is_valley)valley++;
	
//	for(int i=0;i<n;i++)//测试显示过程 
//	{
//		for(int j=0;j<n;j++)
//			cout<<v[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<peak<<" "<<valley<<endl<<endl;
		
	return;
} 

int main()
{
	memset(v,0,sizeof(v));
	
	cin>>n;
	for(int i=0;i<n;i++)//输入图 
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	
	for(int i=0;i<n;i++)//遍历所有点 
		for(int j=0;j<n;j++)
			bfs(i,j);
	
	cout<<peak<<" "<<valley<<endl;//输出结果 
	return 0;	
}
