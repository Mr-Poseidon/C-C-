/*
	C++����ostringstream��istringstream��stringstream�������࣬Ҫʹ�����Ǵ�������ͱ������<sstream>���ͷ�ļ���

	istringstream�Ĺ��캯��ԭ�����£�
	istringstream::istringstream(string str);
	���������Ǵ�string����str�ж�ȡ�ַ���stringstream������԰�һ���ַ�����Ȼ���Կո�Ϊ�ָ����Ѹ��зָ�������
	
	�������Ƿ����Կո�Ϊ���ޣ��ָ�һ���ַ�����
*/ 

//ʾ�����룺 
#include<iostream>
#include<sstream>
#include<string>
int main()
{
    std::string str = "I am coding ...";
    std::istringstream is(str);
    do
    {
        std::string substr;
        is>>substr;
        std::cout << substr << std::endl;
    } while (is);
    return 0;
}
/*
��������� 
	I	
	am 
	coding
	... 
*/ 

//vectorʵ�֣�
#include <vector>
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string str("I am coding ...");
    string buf;
    stringstream ss(str); 
    vector<string> vec; 
    while (ss >> buf)
        vec.push_back(buf);
    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
} 


/*
	������ת����ʹ��ģ��
	��������ɵض��庯��ģ������һ�����������ת�����ض���Ŀ�����͡�
	���磬��Ҫ����������ֵ����int��long��double�ȵ�ת�����ַ�����
	Ҫʹ����һ��string���ͺ�һ������ֵtΪ������to_string()������
	to_string()������tת��Ϊ�ַ�����д��result�С�
	ʹ��str()��Ա��������ȡ���ڲ������һ�ݿ�����
*/ 

//ʾ�����룺 
template<class T>
void to_string(string & result,const T& t)
{

   ostringstream oss;//����һ������ַ�����

   oss<<t;//��ֵ����������

   result=oss.str();//��ȡת������ַ�ת������д��result
}

/*
	���Ը���һ������һ��ͨ�õ�ת��ģ�壬������������֮���ת����
	����ģ��convert()��������ģ�����out_type��in_value�������ǽ�in_valueֵת����out_type���ͣ�
*/ 

//ʾ�����룺
template<class out_type,class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;
	
	stream<<t;//�����д�ֵ
	
	out_type result;//����洢ת�����
	
	stream>>result;//��result��д��ֵ

	return result;
} 

/*
	�ظ�����stringstream����
	���������ڶ��ת����ʹ��ͬһ��stringstream����
	��ס��ÿ��ת��ǰҪʹ��clear()������
	�ڶ��ת�����ظ�ʹ��ͬһ��stringstream��������ÿ�ζ�����һ���µĶ��󣩶������ĺô�����Ч�ʡ�
	stringstream����Ĺ������������ͨ���Ƿǳ��ķ�CPUʱ��ġ�	
*/ 

/*
	���Ը���һ������һ��ͨ�õ�ת��ģ�壬
	������������֮���ת����
	�ڽ��ж��ת����ʱ�򣬱������stringstream�ĳ�Ա����clear()
	����ģ��convert()��������ģ�����out_type��in_value��
	�����ǽ�in_valueֵת����out_type���ͣ�
*/ 

//ʾ�����룺 
template<class out_type,class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;
	stream<<t;//�����д�ֵ
	out_type result;//����洢ת�����
	stream>>result;//��result��д��ֵ
	return result;
}
