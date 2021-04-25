#include<iostream>
#include<cstring>
#include<queue>
#define maxn 1005
using namespace std;

int n;
char map[maxn][maxn];//��ͼ 
int vis[maxn][maxn];//�����ж� 
int dir[4][2]={-1,0,0,-1,1,0,0,1};//�ĸ����� 

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
		
		//�����ܶ���½����˵��ض�������ʧ
		if(map[p.x-1][p.y]=='#'
		&& map[p.x][p.y-1]=='#'
		&& map[p.x+1][p.y]=='#'
		&& map[p.x][p.y+1]=='#')
			disappear=false;
		
		//���ǻ�Ҫ������������С�� 
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
	int block=0;//��ʧС������ 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(map[i][j]=='#' && vis[i][j]==0)
				if(bfs(i,j))//���С����ʧ 
					block++;
		}
	cout<<block<<endl;
	
	return 0;	
}
 
