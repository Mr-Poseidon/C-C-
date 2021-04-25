#include<iostream>
using namespace std;

const int N=100010;

int n;

int head;//head����ͷ�ڵ�
int e[N],ne[N];//e[]��ֵ,ne[]����һ���ڵ���±�
int idx;//�����ڴ��±�

void init()//�������ʼ��
{
    head=-1;//-1����β�ڵ�
    idx=0;//�ڴ��±�Ϊ0
}

void insert_to_head(int x)//��ͷ�ڵ�������ڵ�
{
    e[idx]=x, ne[idx]=head, head=idx++;//�ǵ�idxҪ����
}

void insert(int k,int x)//��k�ڵ�ĺ������ֵΪx�Ľڵ�
{
    e[idx]=x, ne[idx]=ne[k], ne[k]=idx++;
}

void remove(int k)//ɾ��k�ڵ�
{
    ne[k]=ne[ne[k]];
}

int main()
{
    init();//�ǵó�ʼ��
    
    cin>>n;
    while(n--)
    {
        int k,x;
        char op;
        cin>>op;
        
        if(op=='H')//��ͷ�ڵ����
        {
            cin>>x;
            insert_to_head(x);
        }
        else if(op=='D')//ɾ��
        {
            cin>>k;
            if(k==0)head=ne[head];//ɾ��ͷ�ڵ�
            else remove(k-1);//ɾ����ͨ�ڵ�
        }
        else 
        {
            cin>>k>>x;
            insert(k-1,x);//��k�ڵ�������ֵΪx�Ľڵ�
        }
    }
    
    //���
    for(int i=head;i!=-1;i=ne[i])cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}
