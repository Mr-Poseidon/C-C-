#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int a[N],n;//ά������
int f[N];//ά������½����������ֵ
int sd[N];//ά������½������е������
int cnt;//ά����������

int main()
{
    int t;
    while(cin>>t)a[n++]=t;
    
    int ans=0;//ά�����ֵ 
    for(int i=0;i<n;i++)//������½�������
    {
        f[i]=1;
        for(int j=0;j<i;j++)
            if(a[j]>=a[i])
                f[i]=max(f[i],f[j]+1);
                
        ans=max(ans,f[i]);//�����ֵ 
    }
    
    for(int i=0;i<n;i++)//�����е�����
    {
        int k=0;//��ͷ��ʼ
        while(k<cnt && sd[k]<a[i])k++;//��������޷�����
        if(k==cnt)sd[cnt++]=a[i];//��һ���µ�����
        else sd[k]=a[i];//����һ���ɵ�����
    }
    
    printf("%d\n%d",ans,cnt);
    return 0;
}
