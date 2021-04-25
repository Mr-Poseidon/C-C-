#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int w=10,h=10,n=5;
int x1[5]={1,1,4,9,10};
int x2[5]={6,10,4,9,10};
int y1[5]={4,8,1,1,6};
int y2[5]={4,8,10,5,10};

int map[1000][1000];


//��x1,x2������ɢ����������ɢ��֮��Ŀ�� 
int compress(int *x1,int *x2,int w)
{
	vector<int> xs;
	
	for(int i=0;i<n;i++)//�����������ϵ������ 
	{
		for(int d=-1;d<=1;d++)//����������ǰ��λ��,����ϲ� 
		{
			int tx1=x1[i]+d,tx2=x2[i]+d;
			if(1<=tx1 && tx1<=w)xs.push_back(tx1);
			if(1<=tx2 && tx2<=w)xs.push_back(tx2);
		}
	}
	
	sort(xs.begin(),xs.end());//���� 
	xs.erase(unique(xs.begin(),xs.end()),xs.end());//ȥ�� 
	
	for(int i=0;i<n;i++)//�滻���� 
	{
		//�����0���� 
		x1[i]=find(xs.begin(),xs.end(),x1[i])-xs.begin()+1;
		x2[i]=find(xs.begin(),xs.end(),x2[i])-xs.begin()+1;
	} 
	
	return xs.size();//���س��� 
}

int main()
{
	memset(map,0,sizeof(map));
	
	for(int i=0;i<n;i++)//��ɢ��֮ǰ��״̬ 
		for(int x=x1[i];x<=x2[i];x++)
			for(int y=y1[i];y<=y2[i];y++)
			{
				map[x][y]=1;
			}
	
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl<<endl;
	
	w=compress(x1,x2,w);//��ɢ��x������� 
	h=compress(y1,y2,h);//��ɢ��y�������
	
	
	memset(map,0,sizeof(map));
	
	for(int i=0;i<n;i++)//��ɢ��֮���״̬ 
		for(int x=x1[i];x<=x2[i];x++)
			for(int y=y1[i];y<=y2[i];y++)
			{
				map[x][y]=1;
			}
	
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	
	
	return 0;
		
}
