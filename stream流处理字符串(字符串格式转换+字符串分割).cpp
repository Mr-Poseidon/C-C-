/*
	C++引入ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含<sstream>这个头文件。

	istringstream的构造函数原形如下：
	istringstream::istringstream(string str);
	它的作用是从string对象str中读取字符，stringstream对象可以绑定一行字符串，然后以空格为分隔符把该行分隔开来。
	
	下面我们分离以空格为界限，分割一个字符串。
*/ 

//示例代码： 
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
程序输出： 
	I	
	am 
	coding
	... 
*/ 

//vector实现：
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
	在类型转换中使用模板
	你可以轻松地定义函数模板来将一个任意的类型转换到特定的目标类型。
	例如，需要将各种数字值，如int、long、double等等转换成字符串，
	要使用以一个string类型和一个任意值t为参数的to_string()函数。
	to_string()函数将t转换为字符串并写入result中。
	使用str()成员函数来获取流内部缓冲的一份拷贝：
*/ 

//示例代码： 
template<class T>
void to_string(string & result,const T& t)
{

   ostringstream oss;//创建一个输出字符串流

   oss<<t;//把值传递如流中

   result=oss.str();//获取转换后的字符转并将其写入result
}

/*
	可以更进一步定义一个通用的转换模板，用于任意类型之间的转换。
	函数模板convert()含有两个模板参数out_type和in_value，功能是将in_value值转换成out_type类型：
*/ 

//示例代码：
template<class out_type,class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;
	
	stream<<t;//向流中传值
	
	out_type result;//这里存储转换结果
	
	stream>>result;//向result中写入值

	return result;
} 

/*
	重复利用stringstream对象
	如果你打算在多次转换中使用同一个stringstream对象，
	记住再每次转换前要使用clear()方法；
	在多次转换中重复使用同一个stringstream（而不是每次都创建一个新的对象）对象最大的好处在于效率。
	stringstream对象的构造和析构函数通常是非常耗费CPU时间的。	
*/ 

/*
	可以更进一步定义一个通用的转换模板，
	用于任意类型之间的转换。
	在进行多次转换的时候，必须调用stringstream的成员函数clear()
	函数模板convert()含有两个模板参数out_type和in_value，
	功能是将in_value值转换成out_type类型：
*/ 

//示例代码： 
template<class out_type,class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;
	stream<<t;//向流中传值
	out_type result;//这里存储转换结果
	stream>>result;//向result中写入值
	return result;
}
