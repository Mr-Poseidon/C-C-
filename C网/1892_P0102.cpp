/*
#include<iostream>
#include<cstdio>
using namespace std;
 
int main()//·¨Ò» 
{
	int num;
	scanf("%x",&num);
	printf("Hex: 0x%03X\nDecimal: %d\nOctal: %04o",num,num,num);
	return 0;
} 
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	cin>>hex>>n;
	cout<<"Hex: 0x"<<hex<<setw(3)<<setfill('0')<<setiosflags(ios::uppercase)<<n<<endl;
	cout<<"Decimal: "<<dec<<n<<endl;
	cout<<"Octal: "<<oct<<setw(4)<<setfill('0')<<right<<n;
	return 0;
} 
