#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=300005;

int s[N];//ά��ǰ׺�� 
int n,len;
int q[N],hh,tt;//ά���������� 

int main()
{
    scanf("%d%d",&n,&len);
    for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];//���벢ά��ǰ׺�� 
    
    int ans=-0x3f3f3f3f;//��ʼ�� 
    hh=0,tt=0;
    for(int i=0;i<n;i++)
    {
        if(hh<tt && q[hh]==i-len)hh++;//���� 
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//ά��ĩβ 
        q[tt++]=i;//��� 
        ans=max(ans,s[i+1]-s[q[hh]]);//��Ϊǰ׺����r-(l-1),�������s[i+1],Ȼ���ȥǰ���������Сֵ 
    }
    cout<<ans;
    return 0;
}






//-----������--------------------------------------------------------------------------
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=3000005;

//ά������С�ڵ���m�����������е����ֵ������ά������Ϊm���������Сֵ��Ȼ���� s[i]-��Сֵ �������ֵ

int s[N];//ά��ǰ׺��
int n,len;
int q[N],hh,tt;//ά����������

int main()
{
    scanf("%d%d",&n,&len);//����
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];//ά��ǰ׺��
    }
    
    int ans=-0x3f3f3f3f;//��ʼ��
    hh=0,tt=0;
    q[tt++]=0;//s[0]���
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]==i-len-1)hh++;//���ӡ���Ϊǰ׺��0û���á�����Ҫ-1
        ans=max(ans,s[i]-s[q[hh]]);//ά�����ֵ��Ȼ����ǰ׺��Ҫr-(l-1),����Ҫ��ά�������
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//ȥ��ĩβ�����ϵ�Ԫ��
        q[tt++]=i;//���
        
    }
    cout<<ans;//�����
    return 0;
}
