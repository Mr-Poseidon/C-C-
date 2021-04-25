/*
	使用pair.first和pair.second来访问pair中的元素 
	make_pair()返回一个pair对象, make_pair接受隐式类型转换,即自动转换 
	make_pair()使函数有多个返回值 
*/

#include<iostream>
#include<string>
using namespace std;


pair<string,int> getnum(int num)
{
	return make_pair("Nice.\nGet it.",num);//返回值为一个对 
}
int main()
{
	pair<int,int> p(10,12);//创建对象 
	cout<<p.first<<" --- "<<p.second<<endl;//输出
	
	p.first=10.2;
	p.second=12.8;
	cout<<p.first<<" --- "<<p.second<<endl;//输出
	
	p=make_pair(12.5,33.7);
	cout<<p.first<<" --- "<<p.second<<endl;//输出 
	cout<<endl<<endl;
	
	
	pair<string,int> pr=getnum(12);
	cout<<pr.first<<" "<<pr.second<<endl;
	return 0;
} 
