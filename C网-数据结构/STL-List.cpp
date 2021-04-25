//list容器不支持 + 操作,但是可以使用advance()移动函数 

#include<iostream>
#include<list>

using namespace std;


bool cmp(int &a,int &b)
{
	return a>b;//a>b为正确不交换条件 
}
int main()
{
	list<int> li(10,12);
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	if(li.empty())cout<<"list is empty."<<endl;//判断是否为空 
	else cout<<"list is not empty."<<endl;
	
	cout<<"当前元素个数为："<<li.size()<<endl;//元素个数
	
	li.push_front(5);//链首插入 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	li.pop_front();//链首删除 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl; 
	
	li.push_back(78);//链尾插入
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	li.pop_back();//链尾删除 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	list<int> k(10,72);
	
	li.insert(li.begin(),k.begin(),k.end());//链首插入链表 k 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	list<int>::iterator era_begin=li.begin(),era_end=li.begin();//创建一个迭代器 
	advance(era_begin,5);//迭代器位移 
	advance(era_end,15);//迭代器位移 
	li.erase(era_begin,era_end);//删除列表元素 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	li.clear();//清空
	
	for(int i=3;i<11;i++)//构造新list 
		li.push_back(i);
	for(int i=15;i<21;i++)
		li.push_front(i);
		
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	li.sort(cmp);//排列 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	li.reverse();//列表翻转
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	return 0;
}
