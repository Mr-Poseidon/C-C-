#include<cstdio>
#include<iostream>
using namespace std;

const int N=100010;
//idx�ĳ��ֱ�֤��ÿ���ַ����Ķ����ԣ���ʹ��ÿ���¿���һ��·������һ��������ֵ
//0�ȴ�����ڵ㣬Ҳ��������ַ���'\0'��ascii���е�ֵΪ0
int son[N][26],cnt[N],idx;//�ر�ע�����idx
char str[N];

void insert(char* str)//���� 
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//����ַ�����Ӧ��ֵ
        if(!son[p][u])son[p][u] = ++idx;//�����µ�·���������µ�ֵ,0������ڵ�,����idxӦ����++�ٸ�ֵ
        p=son[p][u];
    }
    cnt[p]++;//����ÿ���ַ���������ֵ��������ģ����Կ�����ֵ��������ַ������ֵĴ���
}

int find(char* str)//�����ַ������ֵĴ���
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//����ַ�����Ӧ��ֵ
        if(!son[p][u])return 0;//��·�������ڣ�����0�������0��
        p=son[p][u];
    }
    return cnt[p];//�����ַ������ֵĴ���
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

