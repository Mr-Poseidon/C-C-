#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

/*
	����ά��һ��p[N],�����i������β������������p[i]ת�ƶ�����
	�õݹ���ݼ��ɵó������������ 
*/ 

int a[N];//a[]ά������������
int f[N];//f[i]������a[i]��β��ǰi��������������е�ֵ
int n;

int main()
{
    //����
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++)
    {
        f[i]=1;//ÿ�������ٶ��ǳ���Ϊ1��������
        for(int j=1;j<i;j++)//ע��˴����ܰ���i
            if(a[j]<a[i])//��a[j]<a[i]ʱ��˵��a[i]���Գ�����a[j]����
                f[i]=max(f[i],f[j]+1);//״̬ת�Ʒ���
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)//�������е�����ҳ����ֵ
        ans=max(ans,f[i]);
    printf("%d",ans);
    
    return 0;
}
