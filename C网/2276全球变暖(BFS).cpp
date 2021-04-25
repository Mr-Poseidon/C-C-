#include<iostream>
#include<cstring>
#include<queue>
#define maxn 1005
using namespace std;

int n;
char map[maxn][maxn];//地图 
int vis[maxn][maxn];//访问判断 
int dir[4][2]={-1,0,0,-1,1,0,0,1};//四个方向 

struct Point{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};

bool bfs(int x,int y)
{	
	bool disappear=true;
	queue<Point> q;
	vis[x][y]=1;
	q.push(Point(x,y));
	
	while(!q.empty())
	{
		Point p=q.front();
		q.pop();
		
		//若四周都是陆地则此岛必定不会消失
		if(map[p.x-1][p.y]=='#'
		&& map[p.x][p.y-1]=='#'
		&& map[p.x+1][p.y]=='#'
		&& map[p.x][p.y+1]=='#')
			disappear=false;
		
		//但是还要继续搜索整块小岛 
		for(int i=0;i<4;i++)
		{
			int nx=p.x+dir[i][0];
			int ny=p.y+dir[i][1];
			
			if(nx<0 || nx>=n || ny<0 || ny>=n )continue;
						
			if(map[nx][ny]=='#' && vis[nx][ny]==0)
			{
				vis[nx][ny]=1;
				q.push(Point(nx,ny));
			}
		}
	}
	return disappear;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
			
	memset(vis,0,sizeof(vis));
	int block=0;//消失小岛数量 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(map[i][j]=='#' && vis[i][j]==0)
				if(bfs(i,j))//如果小岛消失 
					block++;
		}
	cout<<block<<endl;
	
	return 0;	
}
 
