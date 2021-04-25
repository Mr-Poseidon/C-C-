/*
��ʽģ�壺
	template <class Key,class T,class Compare,class Allocator> 
	map.insert()����ֵ��һ��ָ�򱻲���Ԫ�صĵ�������һ�������Ƿ�����boolֵ 
	map��������Ҫͨ��make_pair 
	��ֵ�Ժͼ���һ��������Ψһ�� 
	
	Multimap��Map���ƣ�ֻ��һ��������ӳ����ֵ 
	
	��map�Ĺؼ���Ϊintʱ��mapΪ���� ֵ ���͵�һά���飬������ѭmap����
	
	ע��multimap Ϊ һά����ؼ��֣���ά����ֵ �Ķ�ά���飬������ѭmap����
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;


int main()//Multimap
{
	
	multimap<string,int> m;
	
	for(int i=0;i<3;i++)//���� 
		m.insert(pair<string,int>("zun",i));
	for(int i=10;i<13;i++)//���� 
		m.insert(pair<string,int>("jun",i));
	for(int i=20;i<23;i++)//���� 
		m.insert(pair<string,int>("jan",i));
		
	for(multimap<string,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" ӳ���ֵΪ��"<< it->second<<endl;
	cout<<endl;
	
	
	/*
	multimap<int,int> m;
	
	for(int i=0;i<3;i++)//���� 
		m.insert(pair<int,int>(999,i));
	for(int i=10;i<13;i++)//���� 
		m.insert(pair<int,int>(555,i));
	for(int i=20;i<23;i++)//���� 
		m.insert(pair<int,int>(777,i));
		
	for(multimap<int,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" ӳ���ֵΪ��"<< it->second<<endl;
	cout<<endl;
	*/
	return 0;
}


/* 
int main()//Map 
{
	map<char,int> m;//���� 
	
	char ch='a';
	
	for(int i=10;i<26;i++)//�����ֵ�� 
	{
		//����һ��<map<char,int>::iterator,bool>���͵Ķ��� 
		pair<map<char,int>::iterator,bool> it;
		//�����ֵ�� 
		it=m.insert(pair<char,int>(ch++,i));
		if(it.second==true)//�ж��Ƿ����ɹ� 
			cout<<"key"<<i<<" : Insert pair successfully."<<endl;
	}
		
	//�����ֵ�� 
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
		//ע���˴��������ʹ�õ�����ָ��->��û�г�Աfirst,second 
		cout<< it->first <<" --- "<< it->second <<endl; 
	cout<<endl;
	
	cout<<"mapԪ�ظ���Ϊ��"<<m.size()<<endl;
	
	for(ch='a';ch<='g';ch++)//����ָ���ļ���ֵ����ɾ�� 
	{
		cout<<ch<<"��Ӧ��ֵΪ��"<<m.find(ch)->second<<endl;
		m.erase(m.find(ch));
	}
	
	//�����ֵ�� 
	for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
		cout<< it->first <<" --- "<< it->second <<endl; 
	cout<<endl;
	
	cout<<"map�ܹ���������Ԫ�ظ���Ϊ��"<<m.max_size()<<endl; 
	
	return 0;
}
*/ 
