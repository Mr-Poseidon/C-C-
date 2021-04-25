/*
构造函数：
	priority_queue<T,Container,Compare>
	priority_queue<T> //直接输入元素则使用默认容器vector和比较函数 
比较方法：
	less<int> 从大到小排-降序（默认）
	greater<int> 从小到大排-升序 
*/

#include<iostream>
#include<queue>
using namespace std;


struct cmp//自定义比较函数模板结构 
{
	bool operator () (const int &a,const int &b)
	{
		return a<b;//当a<b时交换 
	}
};
int main()
{
	priority_queue<int,vector<int>,cmp> q;
	
	for(int i=0;i<11;i++)
		q.push(i);
	
	cout<<"队头元素为："<<q.top()<<endl; 
	cout<<"优先队列的元素个数为："<<q.size()<<endl;
	
	priority_queue<int,vector<int>,cmp> t(q);//创建一个优先队列t,其内容与q完全相同 
	
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
