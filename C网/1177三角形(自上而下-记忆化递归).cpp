#include<iostream>
#include<algorithm>
using namespace std;

int n=0,ans=0;
int num[100][100],map[100][100];

int dfs(int i,int j)
{
	if(i>=n || j>i)//�ж�Խ�� 
		return 0;
	
	if(map[i][j]!=-1)
		return map[i][j];
	
	int a,b;
	a=dfs(i+1,j);//���� 
	b=dfs(i+1,j+1);//���� 
	return map[i][j] = max(a,b) + num[i][j];//ע�����,�����ظ����� 
}
void init(int n)//��ʼ������ 
{
	ans=0;//������� 
	for(int i=0;i<n;i++)//�������������� 
		for(int j=0;j<=i;j++)
			cin>>num[i][j];
	for(int i=0;i<100;i++)//��ʼ����� 
		for(int j=0;j<100;j++)
			map[i][j]=-1;
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
		cout<<dfs(0,0)<<endl;//������ 
		k--;
	}
	return 0;
} 
