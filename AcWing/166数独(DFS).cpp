#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=9,M=1<<N;

int times[M],map[M];//times[state]ά��state���״̬��1�ĸ�����map[state]ά��state���״̬��Ӧ������
int row[N],col[N],cell[3][3];//ά��ÿ�С�ÿ�С�ÿ��С�Ź�����ÿ�����ֵ���д״̬
char str[100];

//��һ��������ʾÿ�С�ÿ�С�ÿ��С�Ź�����ÿ�������Ƿ���д��״̬
//�ö����Ʊ�ʾÿ��λ�Ƿ��Ѿ���д��0������д��1����գ���δ��д
// 987654321
// 111111111 ����Ӧ�Ķ�����λ��Ϊ1�����λ��û��д

void fillin(int x,int y,int t,bool is_set)//�ڣ�x,y��λ������Ӧ�ĸ�������д����t,is_set��true-��д��false-����
{
    if(is_set)str[x*N+y]='1'+t;//�����ַ������ַ���״̬
    else str[x*N+y]='.';
    
    int v=1<<t;//��ȡ�����ڶ������д����ֵ
    if(is_set==false)v=-v;//ȡ���Ͱ�ֵȡ�������������н�������
    
    row[x]-=v;//�����С��С���Ź����е�״̬
    col[y]-=v;
    cell[x/3][y/3]-=v;
}

void init()
{
    for(int i=0;i<N;i++)row[i]=col[i]=(1<<N)-1;//��ÿ�С�ÿ�е�״̬����ʼ��
    for(int i=0;i<3;i++)//��ʼ����Ź����е�״̬
        for(int j=0;j<3;j++)
            cell[i][j]=(1<<N)-1;
}

int get(int x,int y)//��ȡ��x,y�������п�����д���������ִ����״̬
{
    return row[x] & col[y] & cell[x/3][y/3];
}

int lowbit(int x)//������ĩβ��1��״̬
{
    return x & -x;
}

bool dfs(int cnt)//���ѣ�cnt������Ҫ������ֵĸ���
{
    if(cnt==0)return true;//���ֶ������ˡ�����true
    
    int minv=10;//wά��ÿ��С�Ź�������Ҫ������ֵĸ����������ٵĿ�λ�ĸ��ӿ�ʼ��Ż�����˳��
    int x,y;//ά����д��λ��
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(str[i*N+j]=='.')//������λ��Ϊ��
            {
                int state=get(i,j);//��ȡ��λ�����ڵ�С�ľŹ����״̬
                if(times[state]<minv)//��С����Ҫ������ָ���
                {
                    minv=times[state];//����
                    x=i,y=j;//��¼
                }
            }
    
    int state=get(x,y);//��ȡ��Ҫ ��д�ĸ��� ���ڵľŹ��� ����Ҫ��д���������� �� ״̬
    for(int i=state;i;i-=lowbit(i))//����������Ҫ��д������ �� ״̬
    {
        int t=map[lowbit(i)];//��ȡ��״̬����Ӧ������
        fillin(x,y,t,true);/��д
        if(dfs(cnt-1))return true;
        fillin(x,y,t,false);//����
    }
    
    return false;//ÿ�����ֶ��޷���д������false
}

int main()
{
    //����Ż�
    for(int i=0;i<N;i++)map[1<<i]=i;//��ʼ��ÿ����������Ӧ��״̬
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            times[i]+=i>>j&1;//��ʼ��ÿ��״̬����Ӧ��1�ĸ�����������Ҫ��д�����ֵĸ���
    
    while(cin>>str && str[0]!='e')//����
    {
        init();//��ʼ��
        
        int cnt=0;//cnt��¼��Ҫ��д�����ֵĸ���
        for(int i=0,k=0;i<N;i++)//����ÿ��λ��
            for(int j=0;j<N;j++,k++)
                if(str[k]!='.')//λ�ô�������
                {
                    int t=str[k]-'1';//�ַ�ת��Ϊ����
                    fillin(i,j,t,true);//��д
                }
                else cnt++;//��Ҫ��д�����ֵĸ���+1
        
        dfs(cnt);//����
        
        puts(str);//������
    }
    
    return 0;
}

