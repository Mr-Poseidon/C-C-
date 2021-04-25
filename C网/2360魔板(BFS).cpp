#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
using namespace std;


string bs("12348765"),gs("");
map<string,int> m;//表示该魔板状态是否出现过，出现过标志为1 
map<string,string> mx;//表示该魔板的出现序列，键-魔板，值-序列 
queue<string> q;//广搜队列 




string funA(string s)
{
	s.append(s.begin(),s.begin()+4);
	s.erase(s.begin(),s.begin()+4);
	return s;
}

string funB(string s)
{
	for(int i=3;i>0;i--)
	{
		swap(s[i],s[i-1]);
		swap(s[i+4],s[i+4-1]);
	}
	return s;
}

string funC(string s)
{
	swap(s[1],s[2]);
	swap(s[1],s[5]);
	swap(s[5],s[6]);
	return s;
}

void bfs(queue<string> q)//广搜 
{
	queue<string> qq;
	while(!q.empty())
	{
		string s=q.front();//取出队列头 
		q.pop();//删除队头	
		
		if(s==gs)//达成状态 
			return;
		
		string xx=mx[s];//获取s对应的序列 
		
//		cout<<s<<" "<<mx[s].size()<<" "<<mx[s]<<endl;//测试 
		
		string t;
		
		t=funA(s);//变换魔板 
		if(m[t]!=1)//该魔板未出现过 
		{
			qq.push(t);//入队 
			mx[t]=xx+string("A");//记录生成该魔板所对应的序列 
			//注意：入队后立刻标记魔板可以避免同一个魔板被往后的序列覆盖 
			m[t]=1;//标记该魔板 
		}		
		
		
		t=funB(s);
		if(m[t]!=1)
		{
			qq.push(t);
			mx[t]=xx+string("B");
			m[t]=1;
		}	

		
		t=funC(s);
		if(m[t]!=1)
		{
			qq.push(t);
			mx[t]=xx+string("C");
			m[t]=1;
		}
	}
	bfs(qq);
}

int main()
{
	char ch;
	for(int i=0;i<8;i++)//输入八个字符 
	{
		cin>>ch;
		gs+=ch;
	}
	
	//将字符转换成逻辑的格式 
	string t(gs.begin(),gs.begin()+4);
	t.append(gs.rbegin(),gs.rbegin()+4);
	gs=t;
	
	q.push(bs);//入队 
	mx[bs]="";//构造序列 
	m[bs]=1;//标记 
	
	bfs(q);//广搜 

	//注意：结果输出分两行（题目示例出现错误） 
	cout<<mx[gs].size()<<endl;
	cout<<mx[gs]<<endl;

	
	return 0;
}
