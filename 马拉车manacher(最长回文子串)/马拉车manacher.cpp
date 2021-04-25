// 参考博客 ：https://blog.csdn.net/The_star_is_at/article/details/53354958  
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;

char s[N],sn[2*N];
int le[2*N];

void init()
{
	int k=0;
	
	sn[k++]='@';//防止越界 
	sn[k++]='#';
	for(int i=0;i<strlen(s);i++)
	{
		sn[k++]=s[i];
		sn[k++]='#';
	}
	sn[k]='\0';//防止越界
}
int manacher()
{
	//mx-最大右边界，id-最大右边界的对称中心 
	int mx=0,id;
	int ans=0;//由于新串扩展两倍，所以回文半径会直接等于原串的回文长度 
	for(int i=1;i<strlen(sn);i++)
	{
		// 根据回文串的性质
		// 2*id-i = id-(i-id) 得出i相对id的对称坐标j 
		// min(mx-i,le[2*id-i])将len[j]限制在mx-i里面 
		if(i<mx)le[i]=min(mx-i,le[2*id-i]);
		else le[i]=1;
		
		//判断左右是否相同 
		while(sn[i+le[i]]==sn[i-le[i]])le[i]++;
		
		if(mx<le[i]+i)//判断是否超出最大右边界 
		{
			mx=le[i]+i;
			id=i;
			ans=max(ans,le[i]);//更新最大半径 
		}
	}
	return ans-1;//回文半径不包括本身，所以-1 
}
int main()
{
	cin>>s;
	init();
	cout<<manacher()<<endl;
	//for(int i=0;i<len;i++)cout<<le[i]<<' ';
	return 0;
}
