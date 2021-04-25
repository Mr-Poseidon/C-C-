#include<iostream>
#include<algorithm>
using namespace std;

int n=0;
int num[100][100],map[100][100];

void init(int n)//��ʼ������ 
{
	for(int i=0;i<n;i++)//�������������ݲ���� 
		for(int j=0;j<=i;j++)
		{
			cin>>num[i][j];
			map[i][j]=0;
		}			
}
int main()
{
	ios::sync_with_stdio(false);//���� 
	cin.tie(0);
	cout.tie(0);
	
	int k=0;//k-���Դ��� 
	cin>>k;
	while(k)
	{
		cin>>n;//�������� 
		init(n);//��ʼ������
		
		for(int i=0;i<n;i++)//��ײ����Ǩ�� 
			map[n-1][i]=num[n-1][i];
			 
		for(int i=n-2;i>=0;i--)//���¶��ϵ���
			for(int j=0;j<=i;j++)
			{
				map[i][j] = max( map[i+1][j] , map[i+1][j+1] ) + num[i][j];
			}
		
		cout<<map[0][0]<<endl;//������ 
		k--;
	}
	return 0;
} 
