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
    for(int i=0;i<=n-1;i++)
    {
        if(hh<tt && q[hh]==i-len)hh++;//����
        while(hh<tt && s[q[tt-1]]>s[i])tt--;//ȥ��ĩβ�����ϵ�Ԫ��
        q[tt++]=i;//���
        ans=max(ans,s[i+1]-s[q[hh]]);//ά�����ֵ��Ȼ����ǰ׺��Ҫr-(l-1)������s[i+1]��iҪ+1
    }
    cout<<ans;//�����
    return 0;
}




//--------������---------------------------------------------------------------
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1000010;

//��������ά������ֵ�����ڶ�ͷ
//�����д���Ԫ�ص��±�
//ά��Ԫ���±�ĺô��ǣ���Ԫ����һ���ṹ��Ԫ��ʱ�����Բ�����д�ȽϷ��� == 

int a[N];
int q[N],hh,tt;//ά���������е� 
int n,len;

int main()
{
    scanf("%d%d",&n,&len);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    
    hh=0,tt=0;
    for(int i=0;i<n;i++)//ά����Сֵ�ĵ�������
    {
        if(hh<tt && q[hh]<i-len)hh++;//����
        while(hh<tt && a[q[tt-1]]>a[i])tt--;//ά��β��
        q[tt++]=i;//���
        if(i-len+1>=0)printf("%d ",a[q[hh]]);//�����Сֵ
    }
    
    printf("\n");//����
    
    hh=0,tt=0;
    for(int i=0;i<n;i++)//ά�����ֵ�ĵ�������
    {
        if(hh<tt && q[hh]==i-len)hh++;//����
        while(hh<tt && a[q[tt-1]]<a[i])tt--;//ά��β��
        q[tt++]=i;//���
        if(i-len+1>=0)printf("%d ",a[q[hh]]);//������ֵ
    }
    
    return 0;
}
