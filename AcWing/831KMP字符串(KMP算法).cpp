#include<iostream>
using namespace std;

const int N=1000010;

char p[N],s[N];//p[0],s[0]���ò���
int ne[N];
int n,m;

//�Ӵ��ڻ����������ǲ���� 

int main()
{
    //�˴��������Ӵ�������������
    cin>>n>>p+1>>m>>s+1;
    
    //�Ӵ�����ƥ�䡢���next[]
    //i-������j-�Ӵ�
    //�˴��������ĺ�׺��Ϊ����������������Ϊ�Ӵ�
    for(int i=2,j=0;i<=n;i++)
    {
        while(j && p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    
    //i-������j-�Ӵ�
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&& s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n)cout<<i-n<<" ";
    }
    return 0;
}
