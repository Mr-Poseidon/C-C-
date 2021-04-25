#include<iostream>
#include<queue>
using namespace std;

int n,m;
char map[6][6];
int vis[6][6]={0};
//������Ҫע�ⷽ�� , ������������� {0,-1,-1,0,0,1,1,0}
//˼��һ��Ϊʲô 
int dir[4][2]={1,0,0,1,-1,0,0,-1};//�������� 

int fromx[6][6];//�洢x,y���ԭ�� x ���� 
int fromy[6][6];//�洢x,y���ԭ�� y ���� 

struct Point{
	int x,y;
	Point(int a,int b)
	{
		x=a;
		y=b;
	}
};

void bfs(int x,int y)//���� 
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
			
			if(nx>=0 && nx<5 && ny>=0 && ny<5)//�ڷ�Χ�� 
				if(map[nx][ny]=='0'&&vis[nx][ny]!=1)//�����߲���δ�߹� 
				{
					vis[nx][ny]=1;
					fromx[nx][ny]=p.x;
					fromy[nx][ny]=p.y;					
					q.push(Point(nx,ny));
				}
		}
	}
}

void dfs(int x,int y)//�������·�� 
{
	if(x==fromx[x][y] && y==fromy[x][y])//Դ���Ǳ���˵������� 
		return;
	dfs(fromx[x][y],fromy[x][y]);//���� 
	//ע�⣺ �м�� , �� 
	cout<<"("<<fromx[x][y]<<", "<<fromy[x][y]<<")"<<endl;//�����һ��������� 
	return;
}
int main()
{
	for(int i=0;i<5;i++)//����
		for(int j=0;j<5;j++)
			cin>>map[i][j];
			
	bfs(0,0);//���� 
	dfs(4,4);//���� 
	cout<<"(4, 4)"<<endl;//������һ�������� 
	
	return 0;
}
