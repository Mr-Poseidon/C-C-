#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int n=0;//�������� 
int *out,p=0;//��������Ķ�̬����
char map[10][10];//��ͼ 
int csite[2],msite[2];//ècat��mouseλ�� 

//face[0]-c face[1]-m  face[]�����ĸ����� 
int face[2]={0,0};//�ϱ�-0 �Ҷ�-1 ����-2 ����-3
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int times=0;//ʱ�� 

//visit��¼�߹��ĵط�  [0][][]-cat  [1][][]-mouse
int visit[2][100][3];//[][][0]-����  [][][1]-x [][][2]-y 
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
void ini_map()//����ͼ 
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			in>>map[i][j];
	return;
}
void search_site()//�������� 
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
void outmap()//���ͼ������ʹ�� 
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
bool limit(int s[2])//�鿴�Ƿ���ǽ 
{
	for(int i=0;i<2;i++)
		if(s[i]<0 || s[i]>9)
			return true;
	if(map[s[0]][s[1]]=='*')
		return true;
	return false;	
}
bool test()//�ж��Ƿ�ץ�� 
{
	/* //����ʹ�� 
	cout<<"ʱ��:"<<times<<endl;
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
bool check_note()//����Ƿ��ظ���
{	
	for(int i=times-1;i>=0;i--)
	{
		if(
		//[0][][]-���è
		visit[0][times][0]==visit[0][i][0] &&
		visit[0][times][1]==visit[0][i][1] &&
		visit[0][times][2]==visit[0][i][2] &&
		//[1][][]-����� 
		visit[1][times][0]==visit[1][i][0] &&
		visit[1][times][1]==visit[1][i][1] &&
		visit[1][times][2]==visit[1][i][2]
		)
		return true;
	}
	return false;
}
bool notes()//��¼�߹��ĵ� 
{
	//��¼è 
	visit[0][times][0]=face[0];
	visit[0][times][1]=csite[0];
	visit[0][times][2]=csite[1];
	//��¼���� 
	visit[1][times][0]=face[1];
	visit[1][times][1]=msite[0];
	visit[1][times][2]=msite[1];
}
bool go()//��һ�� 
{
	if(test())
		return false;//����go()ѭ�� 
	
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
	if(limit(s))//ײǽ 
		face[0]=(face[0]+1)%4;//ת�� 
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

