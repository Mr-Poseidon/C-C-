/*
注：string底标由 0 开始 

string中size()和length()的区别：
	size()是容器的大小，length()是字符串序列的长度
	由于在string当中，string对象既是一个容器类型
	底层又是一个字符数组，即字符串的序列
	所以在string当中size()与length()的值将会相等 
	 
*/


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1="hello hong.";//字符串赋值 
	cout<<str1<<endl;//输出 
	
	string str2(str1);//字符串赋值 
	cout<<str2<<endl;//输出
	
	string str3(str1,6);//选取赋值
	cout<<str3<<endl;//输出
	
	string str4(str1,0,5);//选取赋值
	cout<<str4<<endl;//输出
	
	string str5(20,'D');//字符创建 
	cout<<str5<<endl;//输出
	
	cout<<"str5.length = "<<str5.length()<<endl;//length() 
	cout<<"str5.size = "<<str5.size()<<endl;//size() 
	
	string str6(str1.begin(),str1.end());//迭代器创建 
	cout<<str6<<endl;//输出
	
	cout<<str1+" Junqin."<<endl;// +符号重载
	
	string str7="hello hong junqin.";
	cout<<str7<<endl;//输出
	
	//resize()多去少补
	//若没有指定字符,填充内容不确定,此处系统默认为0,即null
	str7.resize(25);
	cout<<str7<<" size: "<<str7.size()<<endl;//输出
	cout<<"默认填充字符ascii值为："<<(int)str7.at(23)<<endl;
	
	str7.resize(10,'.');
	cout<<str7<<endl;//输出
	str7.resize(20,'.');
	cout<<str7<<endl;//输出
	 
	return 0;
} 
