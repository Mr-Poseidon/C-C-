#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

string ss;
char s[4];
vector<int> num;
int base;

void is_ans()
{
	for(int i=0;i<num.size();i++)
		for(int j=i+1;j<num.size();j++)
			for(int k=j+1;k<num.size();k++)
				if(num[k]-num[j] == num[j]-num[i])//�жϵȲ�
					if(num[i]==base || num[j]==base  || num[k]==base)//����ԭ������ 
					{
						cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<endl;
						return;
					}
	cout<<"No"<<endl;
	return;
}
bool is_prime(int num)
{
	for(int i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return false;
	return true;
}
int main()
{

	while(cin>>ss)
	{
		for(int i=0;i<4;i++)
			s[i]=ss[i];	
		base=atoi(s);//��¼ԭ������
		 
		sort(s,s+4);//����sort����ascii�������� 
		num.clear();
		
		do
		{
			int t=atoi(s);
			if(t<1000 || t>9999)continue;
			if(!is_prime(t))continue;
			num.push_back(t);
			
		}while(next_permutation(s,s+4));//ȫ���� 
		
		sort(num.begin(),num.end());//����
		is_ans();
	}
		
	return 0;	
}
