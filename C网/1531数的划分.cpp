#include<iostream>
using namespace std;

int n,map[105][105];//map[]-��¼ͼ

int main()
{
	cin>>n;
	//ע���˴�map[1][0]���и�ֵ1�������˵�i==jʱ��map[i][j]++ 
	for(int i=0;i<=n;i++)//��ֻѡ1��ʱ��ÿ���������ֻ��һ�� 
		map[1][i]=1;
		
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			//����� 
			map[i][j]=map[i-1][j];//�ڲ���iʱ���ճ�j�ķ�����ͬ���ڲ�����iʱ�ճ�j�ķ�����
			if(j>=i)
				map[i][j]+=map[i][j-i];//��iʱ���ճ�j�ķ�����Ҫ���ϴճ�j-i�ķ����� 
			 
			
			/* 
			//ע���������---���´�������ͬ 
			map[i][j]=map[i-1][j];//�ڲ���iʱ���ճ�j�ķ�����ͬ���ڲ�����iʱ�ճ�j�ķ�����
			if(j==i)
				map[i][j]++;//��������i�պõ���jʱ��ֻ��һ�ַ�����ֻ�ñ�����һ���� 
			if(j>i)
				map[i][j]+=map[i][j-i];//��iʱ���ճ�j�ķ�����Ҫ���ϴճ�j-i�ķ�������
			*/ 
		}
	}
	/* 
	for(int i=1;i<=n;i++)//������ӻ� 
	{
		for(int j=0;j<=n;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
	*/ 
	cout<<map[n][n]<<endl;
	return 0;
}
