#include<iostream>
#include<cstdio>
#include<string>
#include<bitset>
#include<cstdlib>
using namespace std;

typedef long long int ll;

string getbit(ll num)//�õ��������ַ��� 
{
	bitset<4> b(num);
	return b.to_string();
}
int is_ans(string s)
{
	string t=s+"0";//���㴦��β�� 
	int ans=0;
	for(int i=1;i<s.size();i++)
	{
		if(t[i-1]=='1')
		{
			ans++;//��ת����++ 
			
			t[i-1]='0';
			
			if(t[i]=='1')t[i]='0';
			else t[i]='1';
			
			if(t[i+1]=='1')t[i+1]='0';
			else t[i+1]='1';
		}
	}
	if(t[s.size()-1]=='1')return -1;//�޽� 
	else return ans;//�н� 
}
int main()
{
	string ss,bs;
	/* 
	//��һ �� ʱ�䳬��6% 
	cin>>ss;
	for(int i=0;i<ss.size();i++)//ת��Ϊ�����ƴ� 
	{
		int num;
		// &(ss.c_str()[i] - �ַ�����iλ��ʼ�����ַ���
		//ֻ����1λ���Ա����ַ������λ����������ǰ��0������ 
		sscanf(&(ss.c_str()[i]),"%1X",&num);//��16���Ƶ���ʽ����1λ 
		bs+=getbit(num);
	}
	*/ 
 
	//���� 
	ll num;
	while(~scanf("%1X",&num))
		bs+=getbit(num);
	
	//cout<<bs<<endl;
	
	while(bs[0]=='0')//ɾ��ǰ��0 
		bs.erase(0,1);
	
	if(bs.size()==0 || bs.size()==1)//������� 
	{
		cout<<bs.size();
		return 0;
	}
		
	int ans1=is_ans(bs);//ǰת3
	
	if(bs[0]=='1')bs[0]='0';//��תǰ��λ 
	else bs[0]='1';
	if(bs[1]=='1')bs[1]='0';
	else bs[1]='1';
	
	int ans2=is_ans(bs);//ǰת2 
	if(ans2!=-1)ans2++;//����н⣬�ͼ��Ϸ�תǰ��λ��һ�� 
	
	if(ans1==-1 && ans2==-1)cout<<"No";//������ 
	if(ans1!=-1 && ans2==-1)cout<<ans1;
	if(ans1==-1 && ans2!=-1)cout<<ans2;
	if(ans1!=-1 && ans2!=-1)cout<<min(ans1,ans2);//���н������С�Ľ�� 
	
	return 0;
} 
