//list������֧�� + ����,���ǿ���ʹ��advance()�ƶ����� 

#include<iostream>
#include<list>

using namespace std;


bool cmp(int &a,int &b)
{
	return a>b;//a>bΪ��ȷ���������� 
}
int main()
{
	list<int> li(10,12);
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	if(li.empty())cout<<"list is empty."<<endl;//�ж��Ƿ�Ϊ�� 
	else cout<<"list is not empty."<<endl;
	
	cout<<"��ǰԪ�ظ���Ϊ��"<<li.size()<<endl;//Ԫ�ظ���
	
	li.push_front(5);//���ײ��� 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	li.pop_front();//����ɾ�� 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl; 
	
	li.push_back(78);//��β����
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	li.pop_back();//��βɾ�� 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	list<int> k(10,72);
	
	li.insert(li.begin(),k.begin(),k.end());//���ײ������� k 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	list<int>::iterator era_begin=li.begin(),era_end=li.begin();//����һ�������� 
	advance(era_begin,5);//������λ�� 
	advance(era_end,15);//������λ�� 
	li.erase(era_begin,era_end);//ɾ���б�Ԫ�� 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	li.clear();//���
	
	for(int i=3;i<11;i++)//������list 
		li.push_back(i);
	for(int i=15;i<21;i++)
		li.push_front(i);
		
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	li.sort(cmp);//���� 
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	li.reverse();//�б�ת
	
	for(list<int>::iterator it=li.begin();it!=li.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	return 0;
}
