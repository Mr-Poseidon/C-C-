#include<iostream>
#include<string>
using namespace std;

string fun(int num)
{
	if(num==0)return "zero";
	if(num==1)return "one";
	if(num==2)return "two";
	if(num==3)return "three";
	if(num==4)return "four";
	if(num==5)return "five";
	if(num==6)return "six";
	if(num==7)return "seven";
	if(num==8)return "eight";
	if(num==9)return "nine";
	if(num==10)return "ten";
	if(num==11)return "eleven";
	if(num==12)return "twelve";
	if(num==13)return "thirteen";
	if(num==14)return "fourteen";
	if(num==15)return "fifteen";
	if(num==16)return "sixteen";
	if(num==17)return "seventeen";
	if(num==18)return "eighteen";
	if(num==19)return "nineteen";
	if(num==20)return "twenty";
	if(num==30)return "thirty";
	if(num==40)return "forty";
	if(num==50)return "fifty";
}

int main()
{
	int h,m;
	string ans;
	cin>>h>>m;
	if(h>20 && h%10!=0)ans+=fun(h/10*10)+" "+fun(h%10);
	else ans+=fun(h);
	
	if(m==0)ans+=" o'clock";
	else if(m>20)ans+=" "+fun(m/10*10)+" "+fun(m%10);
	else ans+=" "+fun(m);
	
	cout<<ans;
	return 0;	
} 
