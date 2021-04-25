#ifndef STORE_H
#define STORE_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std; 



class Store{
	public:
		//ģ�� 
		template<class T> void Serialize(vector<T>& vec,string path);//���л����� 
		template<class T> void Deserialize(vector<T>& vec,string path);//�����л����� 
};

//ģ�廯��
/*
* 	����store.Serialize(P,"People_Data.txt");	
*       ��vector<Class> P�����ݴ�����  People_Data.txt �ı��� 
*/
template<class T> void Store::Serialize(vector<T>& vec,string path)//���л� 
{
	ofstream fout;	
	fout.open(path.c_str(),ios::out|ios::binary);//��������ֽ��� 
		
	for(typename vector<T>::iterator it=vec.begin();it!=vec.end();it++)
	{
		fout.write((char*)&(*it),sizeof(T));//���Ĵ���		
		cout<<"Serialize..."<<endl;
	}
	
	fout.close();
	cout<<"ģ��-���л���ɡ�"<<endl; 
}

template<class T> void Store::Deserialize(vector<T>& vec,string path)//�����л�
{
	ifstream fin;
	fin.open(path.c_str(),ios::in|ios::binary);//���������ֽ��� 
	
	T t; 
	while(fin.peek()!=EOF)//�ж���һ���ַ��Ƿ�Ϊ������ 
	{
		fin.read((char*)&t,sizeof(T));//���Ĵ���		
		cout<<"Deserialize..."<<endl;
				
		vec.push_back(t);
	}
	
	fin.close();
	cout<<"ģ��-�����л���ɡ�"<<endl; 
}


#endif 
