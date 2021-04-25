//��������Ϊѭ��������ctrl + Z ����ѭ�� 

/*
getline()������һ���Ƚϳ����ĺ�������������ֱ���������壬��֪���������������ɶ���һ�����ݡ�
����Ͷ�C++ -- getline()�������÷�˵�����Լ�getline()������Ϊwhile���������⣬�ܽ�һ�£�
��C++�б�����������getline������
��һ�֣���ͷ�ļ�<istream>�У���iostream��ĳ�Ա������
�ڶ��֣���ͷ�ļ�<string>�У�����ͨ������
*/


///////////////////////////////////////////////////////////////////////////////////////////

/*
��һ�֣� ��<istream>�е�getline()����������������ʽ��

istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );

�����ǣ� ��istream�ж�ȡ����n���ַ�(����������Ƿ�)������s��Ӧ�������С���ʹ��û����n���ַ���

�������delim �� �����ﵽ���ƣ����ȡ��ֹ��delim�����ᱻ�����s��Ӧ�������С�
*/

/*
//���̴��룺
#include <iostream>
using namespace std;
//ʹ�ñ�׼�������ͱ�׼�������
// std::cin ;  std::cout ;  std::endl
int main()
{
	char name[256], wolds[256];
	std::cout << "Please input your name: ";
	std::cin.getline(name, 256);
	std::cout << "Please input your wolds: ";
	std::cin.getline(wolds, 256);
	std::cout << "The result is:   " << name << ", " << wolds << std::endl;
	return 0;
}
*/




/*
�ڶ��֣� ��<string>�е�getline����������������ʽ��
	istream& getline (istream&  is, string& str, char delim);
	istream& getline (istream&& is, string& str, char delim);
	istream& getline (istream&  is, string& str);
	istream& getline (istream&& is, string& str);
	
�÷����ϵ�һ�����ƣ����Ƕ�ȡ��istream����Ϊ����is���������ġ���ȡ���ַ���������string���͵�str�С�

�����ı�����
is    ����ʾһ�������������� cin��
str   ��string���͵����ã������洢�������е�����Ϣ��
delim ��char���͵ı����������õĽض��ַ����ڲ��Զ������õ�����£�������\n��������ֹ���롣
*/

//*���̴��룺
#include <iostream>
#include <string>
using namespace std;
int main()
{
	std::string name;	
	std::cout << "Please input your name: ";
	std::getline(std::cin, name);	
	std::cout << "Welcome to here!" << std::ends << name << std::endl;		 	
	std::cout << std::endl;	
	return 0;
}

//������ʱ��ֱ��������\n����EOF�� ����ֹ���������

//**���룺wonderful
//**�����wonderful

//*���̴��룺
/*
int main()
{
	std::string name;
	std::cout << "Please input your name: ";
	std::getline(std::cin, name, '#');
	std::cout << "Welcome to here!" << std::ends << name << std::endl;
	std::cout << std::endl;
	return 0;
}
*/



