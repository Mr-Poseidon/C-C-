#include<cstdio>
#include<iostream>
using namespace std;

const int N=100010;
//idx的出现保证了每个字符串的独立性，它使得每次新开辟一条路径都是一个独立的值
//0既代表根节点，也代表结束字符，'\0'在ascii码中的值为0
int son[N][26],cnt[N],idx;//特别注意理解idx
char str[N];

void insert(char* str)//插入 
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//求出字符所对应的值
        if(!son[p][u])son[p][u] = ++idx;//开辟新的路径、赋上新的值,0代表根节点,所以idx应该先++再赋值
        p=son[p][u];
    }
    cnt[p]++;//由于每个字符串结束的值都是特殊的，所以可以用值来代表该字符串出现的次数
}

int find(char* str)//返回字符串出现的次数
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//求出字符所对应的值
        if(!son[p][u])return 0;//该路径不存在，返回0代表出现0次
        p=son[p][u];
    }
    return cnt[p];//返回字符串出现的次数
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I')insert(str);
        else printf("%d\n",find(str));
    }
    return 0;
}

