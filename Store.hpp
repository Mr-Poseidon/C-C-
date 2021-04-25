#ifndef STORE_H
#define STORE_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std; 



class Store{
	public:
		//模板 
		template<class T> void Serialize(vector<T>& vec,string path);//序列化声明 
		template<class T> void Deserialize(vector<T>& vec,string path);//反序列化声明 
};

//模板化：
/*
* 	例：store.Serialize(P,"People_Data.txt");	
*       将vector<Class> P的数据储存至  People_Data.txt 文本中 
*/
template<class T> void Store::Serialize(vector<T>& vec,string path)//序列化 
{
	ofstream fout;	
	fout.open(path.c_str(),ios::out|ios::binary);//输出流与字节流 
		
	for(typename vector<T>::iterator it=vec.begin();it!=vec.end();it++)
	{
		fout.write((char*)&(*it),sizeof(T));//核心代码		
		cout<<"Serialize..."<<endl;
	}
	
	fout.close();
	cout<<"模板-序列化完成。"<<endl; 
}

template<class T> void Store::Deserialize(vector<T>& vec,string path)//反序列化
{
	ifstream fin;
	fin.open(path.c_str(),ios::in|ios::binary);//输入流与字节流 
	
	T t; 
	while(fin.peek()!=EOF)//判断下一个字符是否为结束符 
	{
		fin.read((char*)&t,sizeof(T));//核心代码		
		cout<<"Deserialize..."<<endl;
				
		vec.push_back(t);
	}
	
	fin.close();
	cout<<"模板-反序列化完成。"<<endl; 
}


#endif 
