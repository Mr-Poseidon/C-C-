/*
	ʹ��pair.first��pair.second������pair�е�Ԫ�� 
	make_pair()����һ��pair����, make_pair������ʽ����ת��,���Զ�ת�� 
	make_pair()ʹ�����ж������ֵ 
*/

#include<iostream>
#include<string>
using namespace std;


pair<string,int> getnum(int num)
{
	return make_pair("Nice.\nGet it.",num);//����ֵΪһ���� 
}
int main()
{
	pair<int,int> p(10,12);//�������� 
	cout<<p.first<<" --- "<<p.second<<endl;//���
	
	p.first=10.2;
	p.second=12.8;
	cout<<p.first<<" --- "<<p.second<<endl;//���
	
	p=make_pair(12.5,33.7);
	cout<<p.first<<" --- "<<p.second<<endl;//��� 
	cout<<endl<<endl;
	
	
	pair<string,int> pr=getnum(12);
	cout<<pr.first<<" "<<pr.second<<endl;
	return 0;
} 
