#include<iostream>
using namespace std;

int n,map[25];//map[]-��¼ͼ 

int dfs(int stairs)
{
	if(stairs==0)return 1;//���� 
	if(stairs<0)return 0;//���� 
	if(map[stairs]!=-1)return map[stairs];//ֱ�ӷ������������ 
	
	return map[stairs]=dfs(stairs-1)+dfs(stairs-3);//ע��˴� 
}

int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)//���ü���ͼ 
		map[i]=-1;
	cout<<dfs(n)<<endl;//������ 
	return 0;
}
