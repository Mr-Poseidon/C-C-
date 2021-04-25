#include<iostream>
#include<queue>
using namespace std;

int n,m;
char map[6][6];
int vis[6][6]={0};
//此题需要注意方向 , 错误的搜索方向 {0,-1,-1,0,0,1,1,0}
//思考一下为什么 
int dir[4][2]={1,0,0,1,-1,0,0,-1};//搜索方向 

int fromx[6][6];//存储x,y点的原点 x 坐标 
int fromy[6][6];//存储x,y点的原点 y 坐标 

struct Point{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};

void bfs(int x,int y)//广搜 
{
	queue<Point> q;
	vis[x][y]=1;
	fromx[x][y]=x;
	fromy[x][y]=y;
	q.push(Point(x,y));
	
	while(!q.empty())
	{
		Point p=q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nx=p.x+dir[i][0];
			int ny=p.y+dir[i][1];
			
			if(nx>=0 && nx<5 && ny>=0 && ny<5)//在范围内 
				if(map[nx][ny]=='0'&&vis[nx][ny]!=1)//可以走并且未走过 
				{
					vis[nx][ny]=1;
					fromx[nx][ny]=p.x;
					fromy[nx][ny]=p.y;					
					q.push(Point(nx,ny));
				}
		}
	}
}

void dfs(int x,int y)//深搜输出路径 
{
	if(x==fromx[x][y] && y==fromy[x][y])//源点是本身，说明是起点 
		return;
	dfs(fromx[x][y],fromy[x][y]);//深搜 
	//注意： 中间的 , 后 
	cout<<"("<<fromx[x][y]<<", "<<fromy[x][y]<<")"<<endl;//输出上一个点的坐标 
	return;
}
int main()
{
	for(int i=0;i<5;i++)//输入
		for(int j=0;j<5;j++)
			cin>>map[i][j];
			
	bfs(0,0);//广搜 
	dfs(4,4);//深搜 
	cout<<"(4, 4)"<<endl;//输出最后一个点坐标 
	
	return 0;
}
