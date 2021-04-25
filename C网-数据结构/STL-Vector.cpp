#include<iostream>
#include<vector>
using namespace std;

// vector <data_type> v;

int main()
{
	int i=0;
	vector<int> v(10,1); //创建 int类型 向量 10个元素 全部为1 
	vector<int>::iterator it;//创建 int类型 迭代器 
	for(it=v.begin();it!=v.end();it++)//输出 
		cout<<(*it)<<" ";
	cout<<endl;
	
	for(int j=0;j<10;j++)//尾部插入 
		v.push_back(i++);
		
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	for(int j=0;j<5;j++)//尾部弹出 
		v.pop_back();
		
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.insert(v.begin(),5,33);//插入 
	
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.erase(v.begin(),v.begin()+3);//删除
	
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.clear();
	
	cout<<"vector元素个数为："<<v.size()<<endl;
	
	v.insert(v.begin(),10,12);
	
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	cout<<"v向量已开辟的最大宽度为："<<v.capacity()<<endl;
	
	cout<<"vector所支持的最大空间值："<<v.max_size()<<endl;
	
	vector<int> n(5,33);//创建 
	
	v.swap(n);//交换 
	
	for(it=v.begin();it!=v.end();it++)//输出
		cout<<(*it)<<" ";
	cout<<endl;
	
	return 0;
}
