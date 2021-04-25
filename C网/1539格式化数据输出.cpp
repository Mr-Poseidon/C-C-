#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	//      10       2   13         2    9     2      13
	cout<<"---------------------------------------------------"<<endl;
	cout<<"COUNTRY     AREA(10K km2)  POP.(10K)  GDP(Billion$)"<<endl;
	cout<<"---------------------------------------------------"<<endl;
 
	string country[5]={"China","Iceland","India","Madagascar","Maldive"};
	double data[5][3]={
	960.00,129500.00,1080.00,
	10.30,27.57,8.20,
	297.47,97000.00,264.80,
	62.70,1635.00,3.60,
	0.0298,27.80,0.23 
	};
	for(int i=0;i<4;i++)
		printf("%-10s  %13.2lf  %9.2lf  %-13.2lf\n",country[i].c_str(),data[i][0],data[i][1],data[i][2]);
	printf("%-10s  %13.4lf  %9.2lf  %-13.2lf\n",country[4].c_str(),data[4][0],data[4][1],data[4][2]);
	cout<<"---------------------------------------------------"<<endl;
	return 0;
} 
