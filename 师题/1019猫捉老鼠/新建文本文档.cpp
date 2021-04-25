#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int n=0;//数据组数 
int *out,p=0;//用于输出的动态数组
char map[10][10];//地图 
int csite[2],msite[2];//猫cat鼠mouse位置 

//face[0]-c face[1]-m  face[]代表四个方向 
int face[2]={0,0};//上北-0 右东-1 下南-2 左西-3
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int times=0;//时间 

//visit记录走过的地方  [0][][]-cat  [1][][]-mouse
int visit[2][100][3];//[][][0]-方向  [][][1]-x [][][2]-y 
ifstream in("map1.txt");

void ini_data()
{
	for(int i=0;i<2;i++)
		for(int j=0;j<100;j++)
		{
			visit[i][j][0]=99;
			visit[i][j][1]=99;
			visit[i][j][2]=99;
		}
	face[0]=0,face[1]=0;
	times=0;
}
void ini_map()//导入图 
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			in>>map[i][j];
	return;
}
void search_site()//搜索坐标 
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(map[i][j]=='c' || map[i][j]=='m')
			{
				if(map[i][j]=='c')
				{
					csite[0]=i;
					csite[1]=j;
					map[i][j]='.'; 
				}
				if(map[i][j]=='m')
				{
					msite[0]=i;
					msite[1]=j;
					map[i][j]='.'; 
				}
			}
	return;	
}
void outmap()//输出图，测试使用 
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return;
}
bool limit(int s[2])//查看是否是墙 
{
	for(int i=0;i<2;i++)
		if(s[i]<0 || s[i]>9)
			return true;
	if(map[s[0]][s[1]]=='*')
		return true;
	return false;	
}
bool test()//判断是否抓到 
{
	/* //测试使用 
	cout<<"时间:"<<times<<endl;
	cout<<"Cat site:"<<csite[0]<<" "<<csite[1]<<" Face:"<<face[0]<<endl;
	cout<<"Mouse site:"<<msite[0]<<" "<<msite[1]<<" Face:"<<face[1]<<endl;
	/**/ 
	if(csite[0]==msite[0] && csite[1]==msite[1])
	{
		out[p++]=times;
		return true;
	}
	return false;
}
bool check_note()//检查是否重复走
{	
	for(int i=times-1;i>=0;i--)
	{
		if(
		//[0][][]-检查猫
		visit[0][times][0]==visit[0][i][0] &&
		visit[0][times][1]==visit[0][i][1] &&
		visit[0][times][2]==visit[0][i][2] &&
		//[1][][]-检查鼠 
		visit[1][times][0]==visit[1][i][0] &&
		visit[1][times][1]==visit[1][i][1] &&
		visit[1][times][2]==visit[1][i][2]
		)
		return true;
	}
	return false;
}
bool notes()//记录走过的点 
{
	//记录猫 
	visit[0][times][0]=face[0];
	visit[0][times][1]=csite[0];
	visit[0][times][2]=csite[1];
	//记录老鼠 
	visit[1][times][0]=face[1];
	visit[1][times][1]=msite[0];
	visit[1][times][2]=msite[1];
}
bool go()//走一步 
{
	if(test())
		return false;//结束go()循环 
	
	notes();
	if(check_note())
	{
		out[p++]=int(0);
		return false;
	}
		
	
	int s[2];
	//cat 
	s[0]=csite[0]+dir[face[0]][0];
	s[1]=csite[1]+dir[face[0]][1];
	if(limit(s))//撞墙 
		face[0]=(face[0]+1)%4;//转向 
	else
	{
		csite[0]=s[0];
		csite[1]=s[1];
	}
	
	//mouse
	s[0]=msite[0]+dir[face[1]][0];
	s[1]=msite[1]+dir[face[1]][1];
	if(limit(s))
		face[1]=(face[1]+1)%4;
	else
	{
		msite[0]=s[0];
		msite[1]=s[1];
	}
	
	times++;
	return true;
}

int main()
{
	in>>n;
	out=new int[n]; 
	for(int i=0;i<n;i++)
	{
		ini_data();
		ini_map();
		search_site();
		while(go());
	}
	for(int i=0;i<n;i++)
		cout<<out[i]<<endl;
	delete[] out;
	return 0;	
}

