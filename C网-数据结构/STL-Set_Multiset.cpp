/*
初始化格式模板：
	template<class T,Compare,Allocator> class set;
	
find()函数可以用来查找元素，但是返回值是迭代器，
所以应该输出时应该表示为*s.find(i),i为所要查找的元素的值
*/

/*
插入迭代器有三种：
	back_inserter(container)
	front_inserter(container)
	inserter(container,pos) //插入到指定的位置之前 
	
注：
	使用前插法和尾插法的时候要注意容器类型，
	是否有push_back()和 push_front()成员， 
	否则会报错。
	可以使用back_inserter的容器是有push_back成员函数的容器，
	比如vector, deque and list等 
	
	Multiset和Set相像，只是支持重复对象 
*/

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()//Multiset
{
	multiset<int> s;
	
	for(int i=0;i<11;i++)//第一次插入集合 
		s.insert(i);
	cout<<"元素个数为："<<s.size()<<endl;
	
	cout<<"集合内容为："; 
	for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl; 
	
	for(int i=0;i<11;i++)//第二次插入集合 
		s.insert(i);
	cout<<"元素个数为："<<s.size()<<endl;
	
	cout<<"集合内容为："; 
	for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl; 
	
	return 0; 
}



/*
int main()//Set 
{
	set<int> s;
	
	for(int i=0;i<11;i++)//创建集合，插入元素 
		s.insert(i);
	
	cout<<"元素个数为："<<s.size()<<endl;
	
	for(int i=0;i<11;i++)//创建集合，插入元素 
		s.insert(i);
	
	cout<<"元素个数为："<<s.size()<<endl;
	
	for(set<int>::iterator it=s.begin();it!=s.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl<<endl;
	
	//创建集合，插入元素 
	set<int> a,b,c;
	for(int i=0;i<10;i++)
		a.insert(i);
	for(int i=7;i<15;i++)
		b.insert(i);
		
	cout<<"Set a: ";
	for(set<int>::iterator it=a.begin();it!=a.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	cout<<"Set b: ";
	for(set<int>::iterator it=b.begin();it!=b.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	
	//合并a,b两个集合,并存放在c集合中 
	set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_union: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	c.clear();//清空集合 
	
	//相交a,b两个集合 
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_intersection: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl;
	
	c.clear();//清空集合
	
	// 求a,b两个集合的差集
	set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_difference: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//输出 
		cout<<*it<<" ";
	cout<<endl; 
	
	return 0;
}
*/

