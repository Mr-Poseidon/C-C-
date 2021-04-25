#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str[3];

int main()
{
	cin>>str[0]>>str[1]>>str[2];
	sort(str,str+3);
	for(int i=0;i<3;i++)
		cout<<str[i]<<endl;
	return 0;
}
