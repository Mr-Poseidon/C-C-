#include<iostream>
#include<string>
using namespace std;

unsigned int num;
string ans;

string invert(string str)
{
	int i=0,j=str.length()-1;
	while(i<j)
	{
		char t;
		t=str.at(i);
		str.at(i)=str.at(j);
		str.at(j)=t;
		i++;
		j--;
	}
	return str;
	
}
string itos(int num)
{
	string str[8]={"0","1","2","3","4","5","6","7"};
	return str[num];
}
int main()
{
	cin>>num;
	while(1)
	{
		ans.append(itos(num%8));
		num/=8;
		if(num==0)
			break;
	}
	ans=invert(ans);
	cout<<ans<<endl;
	return 0;
}
