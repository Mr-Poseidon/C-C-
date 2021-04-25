#include<iostream>
#include<string>
using namespace std;

const int INF=1e5+7;
int nxt[100000][27];//�����i��ʼ,j��ĸ������ֵ�λ�� 


void init(string s)//��ʼ���Զ��� 
{
	int len=s.size();
	
	for(int i=0;i<26;i++)nxt[len][i]=INF;
	for(int i=len-1;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			nxt[i][j]=nxt[i+1][j];//���̳� 
		nxt[i][s[i]-'a']=i;//���� 
	}
}

bool find(string s)//���������� 
{
	int p=-1;//pָ���ʼ��Ϊ-1 
	int len=s.size();
	
	for(int i=0;i<len;i++)
	{
		p=nxt[p+1][s[i]-'a'];//�Զ����Զ����� 
		if(p==INF)return false;
	}
	return true;
} 



int main()
{
	return 0;
}
