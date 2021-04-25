//输入流作为循环条件，ctrl + Z 跳出循环 

/*
getline()函数是一个比较常见的函数。根据名字直接望文生义，就知道这个函数是来完成读入一行数据。
下面就对C++ -- getline()函数的用法说明，以及getline()函数作为while条件的问题，总结一下：
在C++中本质上有两种getline函数：
第一种：在头文件<istream>中，是iostream类的成员函数。
第二种：在头文件<string>中，是普通函数。
*/


///////////////////////////////////////////////////////////////////////////////////////////

/*
第一种： 在<istream>中的getline()函数有两种重载形式：

istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );

作用是： 从istream中读取至多n个字符(包含结束标记符)保存在s对应的数组中。即使还没读够n个字符，

如果遇到delim 或 字数达到限制，则读取终止，delim都不会被保存进s对应的数组中。
*/

/*
//例程代码：
#include <iostream>
using namespace std;
//使用标准输入流和标准输出流。
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
第二种： 在<string>中的getline函数有四种重载形式：
	istream& getline (istream&  is, string& str, char delim);
	istream& getline (istream&& is, string& str, char delim);
	istream& getline (istream&  is, string& str);
	istream& getline (istream&& is, string& str);
	
用法和上第一种类似，但是读取的istream是作为参数is传进函数的。读取的字符串保存在string类型的str中。

函数的变量：
is    ：表示一个输入流，例如 cin。
str   ：string类型的引用，用来存储输入流中的流信息。
delim ：char类型的变量，所设置的截断字符；在不自定义设置的情况下，遇到’\n’，则终止输入。
*/

//*例程代码：
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

//在输入时，直至遇到‘\n’或EOF， 才终止输入操作。

//**输入：wonderful
//**输出：wonderful

//*例程代码：
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



