#include<iostream>
#include<algorithm>
using namespace std;

int num[10];
int main()
{
	for(int i=0;i<10;i++)
		cin>>num[i];
	sort(num,num+10);
	for(int i=0;i<10;i++)
		cout<<num[i]<<endl;
	return 0;
}
