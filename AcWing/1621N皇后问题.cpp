#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1005;

//col[k]�����k���Ƿ��Ѿ�ʹ��
//dg[k]�����k�����Խ����Ƿ��Ѿ�ʹ��
//udg[k]�����k�з��Խ����Ƿ��Ѿ�ʹ��
bool col[N],dg[2*N],udg[2*N];
int a[N];//��ʾ������
int n,m;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i=0;i<m;i++)scanf("%d",&a[i]);
        
        //��ʼ��
        memset(col,false,sizeof(col));
        memset(dg,false,sizeof(dg));
        memset(udg,false,sizeof(udg));
        
        bool f=true;
        for(int i=0;i<m;i++)
        {
            int t=a[i];
            if(!col[t] && !dg[N-t+i] && !udg[t+i])//�ûʺ���Է���
                col[t]=dg[N-t+i]=udg[t+i]=true;//���
            else //�ûʺ��ܷ���
            {
                f=false;
                break;//�˳�ѭ��
            }
        }
        if(f)puts("YES");//������
        else puts("NO");
    }
    return 0;
}
