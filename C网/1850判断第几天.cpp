#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;

int yy,mm,dd,ans;

int main()
{
	while(~scanf("%d/%d/%d",&yy,&mm,&dd))
	{
		ans=0;
		if(mm>=1)
			if(mm==1)ans+=dd;
			else ans+=31;
		if(mm>=2)
			if(mm==2)ans+=dd;
			else if(yy%4==0) ans+=29;
			else ans+=28;
		if(mm>=3)
			if(mm==3)ans+=dd;
			else ans+=31;
		if(mm>=4)
			if(mm==4)ans+=dd;
			else ans+=30;
		if(mm>=5)
			if(mm==5)ans+=dd;
			else ans+=31;
		if(mm>=6)
			if(mm==6)ans+=dd;
			else ans+=30;
		if(mm>=7)
			if(mm==7)ans+=dd;
			else ans+=31;
		if(mm>=8)
			if(mm==8)ans+=dd;
			else ans+=31;
		if(mm>=9)
			if(mm==9)ans+=dd;
			else ans+=30;
		if(mm>=10)
			if(mm==10)ans+=dd;
			else ans+=31;
		if(mm>=11)
			if(mm==11)ans+=dd;
			else ans+=30;
		if(mm==12)
			ans+=dd;
		cout<<ans<<endl;	
	}
	return 0;
} 
