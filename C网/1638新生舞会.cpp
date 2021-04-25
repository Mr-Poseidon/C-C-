#include<iostream> 
#include<cstring> 
using namespace std; 

struct  tstudent 
{ 
	char  name[21]; 
	char  num[21]; 
	char  sex; 
}; 

void  readdata(tstudent  student[],  int  n) 
{ 
	for(int i=0;i<n;i++)
	{
		cin>>student[i].name>>student[i].num>>student[i].sex;
	}
	return;
} 

int  findstudent(tstudent student[],int n,char* data) 
{ 
	if(data  ==  NULL)return  -1; 
	
	for(int i=0;i<n;i++)
		if(strcmp(student[i].name,data)==0 || strcmp(student[i].num,data)==0)
			return student[i].sex;

	return -1;
} 

void solve(tstudent  student[],  int  n,  int  m) 
{ 
	char  x[21],  y[21]; 
	for  (int  i=0;  i< m;  i++)
	{
		cin>>x>>y;
		int a=findstudent(student,n,x);
		int b=findstudent(student,n,y);
		if(a!=b && a!=-1 && b!=-1)
			cout<<"Y"<<endl; 
		else 
			cout<<"N"<<endl; 
	}
	return ; 
}

int  main() 
{ 
	int n,m; 
	tstudent student[1010];
	
	cin>>n; 
	readdata(student,n); 
	cin>>m; 
	solve(student,n,m); 
} 
