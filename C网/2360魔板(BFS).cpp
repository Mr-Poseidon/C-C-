#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;


string bs("12348765"),gs("");
map<string,int> m;//��ʾ��ħ��״̬�Ƿ���ֹ������ֹ���־Ϊ1 
map<string,string> mx;//��ʾ��ħ��ĳ������У���-ħ�壬ֵ-���� 
queue<string> q;//���Ѷ��� 




string funA(string s)
{
	s.append(s.begin(),s.begin()+4);
	s.erase(s.begin(),s.begin()+4);
	return s;
}

string funB(string s)
{
	for(int i=3;i>0;i--)
	{
		swap(s[i],s[i-1]);
		swap(s[i+4],s[i+4-1]);
	}
	return s;
}

string funC(string s)
{
	swap(s[1],s[2]);
	swap(s[1],s[5]);
	swap(s[5],s[6]);
	return s;
}

void bfs(queue<string> q)//���� 
{
	queue<string> qq;
	while(!q.empty())
	{
		string s=q.front();//ȡ������ͷ 
		q.pop();//ɾ����ͷ	
		
		if(s==gs)//���״̬ 
			return;
		
		string xx=mx[s];//��ȡs��Ӧ������ 
		
//		cout<<s<<" "<<mx[s].size()<<" "<<mx[s]<<endl;//���� 
		
		string t;
		
		t=funA(s);//�任ħ�� 
		if(m[t]!=1)//��ħ��δ���ֹ� 
		{
			qq.push(t);//��� 
			mx[t]=xx+string("A");//��¼���ɸ�ħ������Ӧ������ 
			//ע�⣺��Ӻ����̱��ħ����Ա���ͬһ��ħ�屻��������и��� 
			m[t]=1;//��Ǹ�ħ�� 
		}		
		
		
		t=funB(s);
		if(m[t]!=1)
		{
			qq.push(t);
			mx[t]=xx+string("B");
			m[t]=1;
		}	

		
		t=funC(s);
		if(m[t]!=1)
		{
			qq.push(t);
			mx[t]=xx+string("C");
			m[t]=1;
		}
	}
	bfs(qq);
}

int main()
{
	char ch;
	for(int i=0;i<8;i++)//����˸��ַ� 
	{
		cin>>ch;
		gs+=ch;
	}
	
	//���ַ�ת�����߼��ĸ�ʽ 
	string t(gs.begin(),gs.begin()+4);
	t.append(gs.rbegin(),gs.rbegin()+4);
	gs=t;
	
	q.push(bs);//��� 
	mx[bs]="";//�������� 
	m[bs]=1;//��� 
	
	bfs(q);//���� 

	//ע�⣺�����������У���Ŀʾ�����ִ��� 
	cout<<mx[gs].size()<<endl;
	cout<<mx[gs]<<endl;

	
	return 0;
}
