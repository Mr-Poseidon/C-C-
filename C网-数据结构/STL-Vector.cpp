#include<iostream>
#include<vector>
using namespace std;

// vector <data_type> v;

int main()
{
	int i=0;
	vector<int> v(10,1); //���� int���� ���� 10��Ԫ�� ȫ��Ϊ1 
	vector<int>::iterator it;//���� int���� ������ 
	for(it=v.begin();it!=v.end();it++)//��� 
		cout<<(*it)<<" ";
	cout<<endl;
	
	for(int j=0;j<10;j++)//β������ 
		v.push_back(i++);
		
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	for(int j=0;j<5;j++)//β������ 
		v.pop_back();
		
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.insert(v.begin(),5,33);//���� 
	
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.erase(v.begin(),v.begin()+3);//ɾ��
	
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	v.clear();
	
	cout<<"vectorԪ�ظ���Ϊ��"<<v.size()<<endl;
	
	v.insert(v.begin(),10,12);
	
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	cout<<"v�����ѿ��ٵ������Ϊ��"<<v.capacity()<<endl;
	
	cout<<"vector��֧�ֵ����ռ�ֵ��"<<v.max_size()<<endl;
	
	vector<int> n(5,33);//���� 
	
	v.swap(n);//���� 
	
	for(it=v.begin();it!=v.end();it++)//���
		cout<<(*it)<<" ";
	cout<<endl;
	
	return 0;
}
