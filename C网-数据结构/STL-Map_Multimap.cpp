/*
格式模板：
	template <class Key,class T,class Compare,class Allocator> 
	map.insert()返回值是一个指向被插入元素的迭代器和一个描述是否插入的bool值 
	map插入数据要通过make_pair 
	键值对和集合一样，具有唯一性 
	
	Multimap和Map相似，只是一个键可以映射多个值 
	
	当map的关键字为int时，map为储存 值 类型的一维数组，并且遵循map规则
	
	注：multimap 为 一维储存关键字，二维储存值 的二维数组，并且遵循map规则
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;


int main()//Multimap
{
	
	multimap<string,int> m;
	
	for(int i=0;i<3;i++)//插入 
		m.insert(pair<string,int>("zun",i));
	for(int i=10;i<13;i++)//插入 
		m.insert(pair<string,int>("jun",i));
	for(int i=20;i<23;i++)//插入 
		m.insert(pair<string,int>("jan",i));
		
	for(multimap<string,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" 映射的值为："<< it->second<<endl;
	cout<<endl;
	
	
	/*
	multimap<int,int> m;
	
	for(int i=0;i<3;i++)//插入 
		m.insert(pair<int,int>(999,i));
	for(int i=10;i<13;i++)//插入 
		m.insert(pair<int,int>(555,i));
	for(int i=20;i<23;i++)//插入 
		m.insert(pair<int,int>(777,i));
		
	for(multimap<int,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" 映射的值为："<< it->second<<endl;
	cout<<endl;
	*/
	return 0;
}


/* 
int main()//Map 
{
	map<char,int> m;//创建 
	
	char ch='a';
	
	for(int i=10;i<26;i++)//插入键值对 
	{
		//创建一个<map<char,int>::iterator,bool>类型的对象 
		pair<map<char,int>::iterator,bool> it;
		//插入键值对 
		it=m.insert(pair<char,int>(ch++,i));
		if(it.second==true)//判断是否插入成功 
			cout<<"key"<<i<<" : Insert pair successfully."<<endl;
	}
		
	//输出键值对 
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
		//注：此处输出必须使用迭代器指针->，没有成员first,second 
		cout<< it->first <<" --- "<< it->second <<endl; 
	cout<<endl;
	
	cout<<"map元素个数为："<<m.size()<<endl;
	
	for(ch='a';ch<='g';ch++)//查找指定的键的值，并删除 
	{
		cout<<ch<<"对应的值为："<<m.find(ch)->second<<endl;
		m.erase(m.find(ch));
	}
	
	//输出键值对 
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" --- "<< it->second <<endl; 
	cout<<endl;
	
	cout<<"map能够保存的最大元素个数为："<<m.max_size()<<endl; 
	
	return 0;
}
*/ 
