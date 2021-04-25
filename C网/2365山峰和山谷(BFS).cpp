#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n;
int v[1005][1005];
int map[1005][1005];
int peak=0,valley=0;
int dir[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};//�˸����� 

struct Point{
	int x,y;
}point;


void bfs(int x,int y)
{
	bool is_peak=true,is_valley=true;//�жϸÿ���ɽ�廹��ɽ�� 
	
	if(v[x][y]==1)return;//���ʹ������� 
	queue<Point> block;//����� 
	
	v[x][y]=1;//��� 
	
	Point p;//������ 
	p.x=x;
	p.y=y;
	block.push(p);
	
	while(!block.empty())
	{
		Point p=block.front();
		block.pop();
		
		
		for(int i=0;i<8;i++)//������Χ�˸����� 
		{
			int x=p.x+dir[i][0];
			int y=p.y+dir[i][1];
			if(x>=0 && x<n && y>=0 && y<n)//δԽ�� 
			{
				if(map[x][y]==map[p.x][p.y])//���Ϊ�� 
				{
					if(v[x][y]==0)//δ���� 
					{
						Point t;
						t.x=x;
						t.y=y;
						block.push(t);
						v[x][y]=1;//��� 
						continue;
					}	
				}
				else//����Ϊ�� 
				{
					if(map[x][y]>map[p.x][p.y])is_peak=false;//�߱Ƚϸ� 
					if(map[x][y]<map[p.x][p.y])is_valley=false;//�߱Ƚϵ� 
					continue;
				}
			}
		}
	}
	if(is_peak)peak++;
	if(is_valley)valley++;
	
//	for(int i=0;i<n;i++)//������ʾ���� 
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
	for(int i=0;i<n;i++)//����ͼ 
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	
	for(int i=0;i<n;i++)//�������е� 
		for(int j=0;j<n;j++)
			bfs(i,j);
	
	cout<<peak<<" "<<valley<<endl;//������ 
	return 0;	
}
