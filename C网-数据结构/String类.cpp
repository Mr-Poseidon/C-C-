/*
ע��string�ױ��� 0 ��ʼ 

string��size()��length()������
	size()�������Ĵ�С��length()���ַ������еĳ���
	������string���У�string�������һ����������
	�ײ�����һ���ַ����飬���ַ���������
	������string����size()��length()��ֵ������� 
	 
*/


#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1="hello hong.";//�ַ�����ֵ 
	cout<<str1<<endl;//��� 
	
	string str2(str1);//�ַ�����ֵ 
	cout<<str2<<endl;//���
	
	string str3(str1,6);//ѡȡ��ֵ
	cout<<str3<<endl;//���
	
	string str4(str1,0,5);//ѡȡ��ֵ
	cout<<str4<<endl;//���
	
	string str5(20,'D');//�ַ����� 
	cout<<str5<<endl;//���
	
	cout<<"str5.length = "<<str5.length()<<endl;//length() 
	cout<<"str5.size = "<<str5.size()<<endl;//size() 
	
	string str6(str1.begin(),str1.end());//���������� 
	cout<<str6<<endl;//���
	
	cout<<str1+" Junqin."<<endl;// +��������
	
	string str7="hello hong junqin.";
	cout<<str7<<endl;//���
	
	//resize()��ȥ�ٲ�
	//��û��ָ���ַ�,������ݲ�ȷ��,�˴�ϵͳĬ��Ϊ0,��null
	str7.resize(25);
	cout<<str7<<" size: "<<str7.size()<<endl;//���
	cout<<"Ĭ������ַ�asciiֵΪ��"<<(int)str7.at(23)<<endl;
	
	str7.resize(10,'.');
	cout<<str7<<endl;//���
	str7.resize(20,'.');
	cout<<str7<<endl;//���
	 
	return 0;
} 
