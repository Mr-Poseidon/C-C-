#include<direct.h>//mkdir(),rmdir() 
#include<stdio.h>//remove()
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	if(mkdir("data")==0)//����Ŀ¼ 
		cout<<"data file create."<<endl;
	if(access("data",0)==0)
		cout<<"access data file."<<endl;
	

	fstream f;
	f.open("./data/01.txt");//�����ı� 

	
	
	if(remove("01.txt")==0)//ɾ���ļ� 
		cout<<"txt removed already."<<endl;
		
	if(rmdir("./data")==0)
		cout<<"data file removed already."<<endl;
			
	if(access("data",0)==-1)
		cout<<"data file did not exit."<<endl;
	else
		cout<<"data file exit."<<endl;

	
	return 0;
}


