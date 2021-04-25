#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

ifstream in("input.txt"); 
ofstream out("output.txt"); 

int k,limit=30;
string t;

bool text(string t)
{
	char a[t.length()];
	strcpy(a,t.c_str());
	
	int i=0,j;
	j=strlen(a)-1;
	
	for(i=0 ; i<j ; i++,j--)
		if(a[i]!=a[j]) return false;
			
	return true;
}
char itoc(int num)
{
	char to_char[]={'0','1','2','3',
					'4','5','6','7',
					'8','9','a','b',
					'c','d','e','f'};
	return to_char[num];
}
int ctoi(char c)
{
	char to_char[]={'0','1','2','3',
					'4','5','6','7',
					'8','9','a','b',
					'c','d','e','f'};
	int i;
	for(i=0;i<16;i++)
		if(to_char[i]==c)
			return i;
}


string add(string t1,string t2,int k)
{
	
	int f=0;
	char a[t1.length()],b[t2.length()];
	strcpy(a,t1.c_str()); 
	strcpy(b,t2.c_str());
	
	int i=t1.length()-1,j; 
	
	char c[i+3];
	

	memset(c,'\0',sizeof(c));
	
	j=0;
	while(i>=0)
	{
		int sum=0;
		if(f==1)
		{
			sum=1;
			f=0;
		}
		
		sum += ( ctoi(a[i]) + ctoi(b[i]) );
		c[j++] = itoc(sum%k);
		if((sum/k)!=0)
			f=1;
		i--;
	}
	
	if(f==1)
		c[j]='1';
		
	j=strlen(c)-1;
	for(i=0 ; i<j ; i++,j--)
	{
		char tt;
		tt=c[i];c[i]=c[j];c[j]=tt;
	}
	t1=c;
	return t1;
}

string trans(string t)
{
	int i,j;
	j=t.length()-1;
	
	char a[t.length()];
	strcpy(a,t.c_str());
	
	for(i=0 ; i<j ; i++,j--)
	{
		char tt;
		tt=a[i];a[i]=a[j];a[j]=tt;
	}
	
	t=a;
	return t; 
}
int main()
{
	cin>>k>>t;
	int i;

	for(i=1;i<=limit;i++)
	{	
		t=add(t,trans(t),k);
		
		
		if(text(t))
		{
			cout<<"STEP="<<i;
			return 0;
		}
	}
	cout<<"Impossible!"<<endl;
	return 0;
}
