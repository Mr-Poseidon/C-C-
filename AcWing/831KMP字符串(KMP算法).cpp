#include<iostream>
using namespace std;

const int N=1000010;

char p[N],s[N];//p[0],s[0]弃置不用
int ne[N];
int n,m;

//子串在滑动、主串是不变的 

int main()
{
    //此处先输入子串，再输入主串
    cin>>n>>p+1>>m>>s+1;
    
    //子串自身匹配、求出next[]
    //i-主串，j-子串
    //此处将主串的后缀作为主串、主串整串作为子串
    for(int i=2,j=0;i<=n;i++)
    {
        while(j && p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    
    //i-主串，j-子串
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&& s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n)cout<<i-n<<" ";
    }
    return 0;
}
