#include<iostream>
#include<cstring>
#include<queue>
#define maxn 1005
using namespace std;

int N,K;
char map[maxn][maxn];//储存地图 
int vis[maxn][maxn][11];//i,j代表坐标，k代表剩余的无敌步数 
int dir[4][2]={0,-1,-1,0,0,1,1,0};//四个方向 


struct Point{
	int x,y;
	int k;
	int step;
	Point(int a,int b,int c,int d)
	{
		x=a;y=b;k=c;step=d;//此处注意细节，避免写错 
	}
};

void bfs(int sx,int sy,int ex,int ey)
{	
	memset(vis,0,sizeof(vis));
	queue<Point> q;
		
	vis[sx][sy][0]=1;
	q.push(Point(sx,sy,0,0));
	
	
	while(!q.empty())
	{
		Point p=q.front();
		q.pop();
		
//		cout<<p.x<<" "<<p.y<<" "<<p.k<<" "<<p.step<<endl;
		
		if(p.x==ex && p.y==ey)
		{
			cout<<p.step<<endl;
			return;
		}
		
		
		for(int i=0;i<4;i++)
		{
			int nx=p.x+dir[i][0];
			int ny=p.y+dir[i][1];
			
			//剪枝 
			if(p.k && vis[nx][ny][p.k-1])continue;
			if(!p.k && vis[nx][ny][p.k])continue;
			
			if(nx>=0 && nx<N && ny>=0 && ny<N && map[nx][ny]!='#')
			{
				if(!p.k && map[nx][ny]=='X')continue;//没有无敌遇到陷阱 
					
				if(map[nx][ny]=='%')//无敌道具 
				{
					map[nx][ny]='.';
					vis[nx][ny][K]=1;
					q.push(Point(nx,ny,K,p.step+1));
					continue;
				}
				if(map[nx][ny]=='.' && p.k)//有无敌正常走 
				{
					vis[nx][ny][p.k-1]=1;
					q.push(Point(nx,ny,p.k-1,p.step+1));
					continue;
				}
				if(map[nx][ny]=='.' && p.k==0)//没有无敌正常走 
				{
					vis[nx][ny][p.k]=1;
					q.push(Point(nx,ny,p.k,p.step+1));
					continue;
				}
				if(map[nx][ny]=='X' && p.k)//有无敌遇到陷阱 
				{
					vis[nx][ny][p.k-1]=1;
					q.push(Point(nx,ny,p.k-1,p.step+1));
					continue;
				}
			}
		} 
	}
	cout<<"-1"<<endl;
	return;	
}

int main()
{
	cin>>N>>K;
	
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++)
			cin>>map[i][j];	
	
	bfs(0,0,N-1,N-1);
	
	return 0;
}
