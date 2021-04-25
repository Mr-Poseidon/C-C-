/*
���캯����
	priority_queue<T,Container,Compare>
	priority_queue<T> //ֱ������Ԫ����ʹ��Ĭ������vector�ͱȽϺ��� 
�ȽϷ�����
	less<int> �Ӵ�С��-����Ĭ�ϣ�
	greater<int> ��С������-���� 
*/

#include<iostream>
#include<queue>
using namespace std;


struct cmp//�Զ���ȽϺ���ģ��ṹ 
{
	bool operator () (const int &a,const int &b)
	{
		return a<b;//��a<bʱ���� 
	}
};
int main()
{
	priority_queue<int,vector<int>,cmp> q;
	
	for(int i=0;i<11;i++)
		q.push(i);
	
	cout<<"��ͷԪ��Ϊ��"<<q.top()<<endl; 
	cout<<"���ȶ��е�Ԫ�ظ���Ϊ��"<<q.size()<<endl;
	
	priority_queue<int,vector<int>,cmp> t(q);//����һ�����ȶ���t,��������q��ȫ��ͬ 
	
	while(!t.empty())
	{
		cout<<t.top()<<" ";
		t.pop();
	}
	cout<<endl; 

	/*	
	priority_queue<int,vector<int>,greater<int> > a;
	for(int i=0;i<11;i++)
		a.push(i);
	
	while(!a.empty())
	{
		cout<<a.top()<<" ";
		a.pop();
	}
	cout<<endl;	
	*/ 
	
	return 0;
}
