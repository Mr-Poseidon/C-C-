/*
	注意：
		此题点的范围为[0,L],有包含L,题目所给范围有误 
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Point{
	int x,y;
}point;

int n,l;
int v[305][305];
int step[305][305];
int dir[8][2]={-2,-1,-2,1,2,-1,2,1,-1,-2,-1,2,1,-2,1,2};

void bfs(int sx,int sy,int ex,int ey)
{
	memset(v,0,sizeof(v));
	memset(step,0,sizeof(step));
		
	queue<Point> q;
	Point pp;
	pp.x=sx;
	pp.y=sy;
	
	v[sx][sy]=1;
	step[sx][sy]=0;
	q.push(pp);
	
	while(!q.empty())
	{
		Point p=q.front();
		q.pop();
		
		int x=p.x;
		int y=p.y;
		int sstep=step[x][y];
		
		if(x==ex && y==ey)return;
		
		for(int i=0;i<8;i++)
		{
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			
			if(nx>=0 && nx<=l && ny>=0 && ny<=l && v[nx][ny]==0)//此处有包含L,题目所给范围有误 
			{	
				v[nx][ny]=1;
				step[nx][ny]=sstep+1;
				Point t;
				t.x=nx;
				t.y=ny;
				q.push(t);
			}
		}
	}
}

int main()
{
	cin>>n;
	while(n--)
	{	
		cin>>l;
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		bfs(sx,sy,ex,ey);
		cout<<step[ex][ey]<<endl;
	}
}
