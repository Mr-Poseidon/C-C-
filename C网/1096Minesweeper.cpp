#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int field=1;//�����־ 

void fun(int a,int b)
{
	char** map=(char**)malloc(sizeof(char*)*a);//��̬�������� 
	for(int i=0;i<a;i++)
		map[i]=(char*)malloc(sizeof(char)*b);
	
	for(int i=0;i<a;i++)//�����ͼ 
	{
		for(int j=0;j<b;j++)
			scanf("%c",&map[i][j]);
		getchar();//�������з� 
	}
		
	
	for(int i=0;i<a;i++)//������ͼ������ 
		for(int j=0;j<b;j++)
		{
			if(map[i][j]=='*')
				continue;
			else//�����ܱߵ������� 
			{
				int num=0;
				for(int k=-1;k<=1;k++)
					for(int l=-1;l<=1;l++)
					{
						if(i+k<0 || i+k>=a)continue;
						if(j+l<0 || j+l>=b)continue;
						if(k==0 && l==0)continue;
						if(map[i+k][j+l]=='*')
							num++;
					}
				map[i][j]='0'+num;//��ǵ������� 
			}
		}
	
	cout<<"Field #"<<field<<":"<<endl;//�����ͼ 
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	
	for(int i=0;i<a;i++)//�ͷŶ�̬���� 
		free(map[i]);
	free(map);
	field++;//�����־�Լ�	
}
int main()
{
	int a,b; 
	while(~scanf("%d%d",&a,&b) && a!=0 && b!=0)
	{
		getchar();//�������з�������Խ������ַ����������Ӱ�� 
		fun(a,b);
		cout<<endl;//�������и��� 
	}	
	return 0;
}
