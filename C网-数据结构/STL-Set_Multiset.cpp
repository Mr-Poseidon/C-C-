/*
��ʼ����ʽģ�壺
	template<class T,Compare,Allocator> class set;
	
find()����������������Ԫ�أ����Ƿ���ֵ�ǵ�������
����Ӧ�����ʱӦ�ñ�ʾΪ*s.find(i),iΪ��Ҫ���ҵ�Ԫ�ص�ֵ
*/

/*
��������������֣�
	back_inserter(container)
	front_inserter(container)
	inserter(container,pos) //���뵽ָ����λ��֮ǰ 
	
ע��
	ʹ��ǰ�巨��β�巨��ʱ��Ҫע���������ͣ�
	�Ƿ���push_back()�� push_front()��Ա�� 
	����ᱨ��
	����ʹ��back_inserter����������push_back��Ա������������
	����vector, deque and list�� 
	
	Multiset��Set����ֻ��֧���ظ����� 
*/

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()//Multiset
{
	multiset<int> s;
	
	for(int i=0;i<11;i++)//��һ�β��뼯�� 
		s.insert(i);
	cout<<"Ԫ�ظ���Ϊ��"<<s.size()<<endl;
	
	cout<<"��������Ϊ��"; 
	for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl; 
	
	for(int i=0;i<11;i++)//�ڶ��β��뼯�� 
		s.insert(i);
	cout<<"Ԫ�ظ���Ϊ��"<<s.size()<<endl;
	
	cout<<"��������Ϊ��"; 
	for(multiset<int>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it<<" ";
	cout<<endl; 
	
	return 0; 
}



/*
int main()//Set 
{
	set<int> s;
	
	for(int i=0;i<11;i++)//�������ϣ�����Ԫ�� 
		s.insert(i);
	
	cout<<"Ԫ�ظ���Ϊ��"<<s.size()<<endl;
	
	for(int i=0;i<11;i++)//�������ϣ�����Ԫ�� 
		s.insert(i);
	
	cout<<"Ԫ�ظ���Ϊ��"<<s.size()<<endl;
	
	for(set<int>::iterator it=s.begin();it!=s.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl<<endl;
	
	//�������ϣ�����Ԫ�� 
	set<int> a,b,c;
	for(int i=0;i<10;i++)
		a.insert(i);
	for(int i=7;i<15;i++)
		b.insert(i);
		
	cout<<"Set a: ";
	for(set<int>::iterator it=a.begin();it!=a.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	cout<<"Set b: ";
	for(set<int>::iterator it=b.begin();it!=b.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	
	//�ϲ�a,b��������,�������c������ 
	set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_union: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	c.clear();//��ռ��� 
	
	//�ཻa,b�������� 
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_intersection: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl;
	
	c.clear();//��ռ���
	
	// ��a,b�������ϵĲ
	set_difference(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
	
	cout<<"set_difference: ";
	for(set<int>::iterator it=c.begin();it!=c.end();it++)//��� 
		cout<<*it<<" ";
	cout<<endl; 
	
	return 0;
}
*/

