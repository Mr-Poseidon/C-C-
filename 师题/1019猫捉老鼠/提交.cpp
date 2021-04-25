#include<iostream>
#include<string>

using namespace std;

int n=0,p=0;
int* out;
char map[10][10];
int csite[2],msite[2];
int face[2]={0,0};
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int times=0;
int visit[2][100][3];

string str;

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
void ini_map()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin>>map[i][j];
	return;
}
void search_site()
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

bool limit(int s[2])
{
	for(int i=0;i<2;i++)
		if(s[i]<0 || s[i]>9)
			return true;
	if(map[s[0]][s[1]]=='*')
		return true;
	return false;	
}
bool test()
{
	if(csite[0]==msite[0] && csite[1]==msite[1])
	{
		out[p++]=times;
		return true;
	}
	return false;
}
bool check_note()
{	
	for(int i=times-1;i>=0;i--)
	{
		if(
		visit[0][times][0]==visit[0][i][0] &&
		visit[0][times][1]==visit[0][i][1] &&
		visit[0][times][2]==visit[0][i][2] &&

		visit[1][times][0]==visit[1][i][0] &&
		visit[1][times][1]==visit[1][i][1] &&
		visit[1][times][2]==visit[1][i][2]
		)
		return true;
	}
	return false;
}
bool notes() 
{

	visit[0][times][0]=face[0];
	visit[0][times][1]=csite[0];
	visit[0][times][2]=csite[1];
 
	visit[1][times][0]=face[1];
	visit[1][times][1]=msite[0];
	visit[1][times][2]=msite[1];
}
bool go()
{
	if(test())
		return false;
	
	notes();
	if(check_note())
	{
		out[p++]=int(0);
		return false;
	}
		
	
	int s[2];

	s[0]=csite[0]+dir[face[0]][0];
	s[1]=csite[1]+dir[face[0]][1];
	if(limit(s))
		face[0]=(face[0]+1)%4;
	else
	{ 
		csite[0]=s[0];
		csite[1]=s[1];
	}
	

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
	cin>>n;
	out=new int[n];
	for(int i=0;i<n;i++)
	{
		if(i!=0)getline(cin,str);
		ini_data();
		ini_map();
		search_site();
		while(go());
	}
	for(int i=0;i<n;i++)
	{
		cout<<out[i];
		if(i==n-1)break;
		cout<<endl;
	} 
		
	delete[] out;
	return 0;	
}

