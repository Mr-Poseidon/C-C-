#include<iostream>
#include<string>
using namespace std;

const int N=100010;

//e[]������ֵ��l[]��������˵㣬r[]�������Ҷ˵�
int e[N],l[N],r[N];
int idx;//�ڴ��±�

void init()//��ʼ������
{
    //0������˵�,1�����Ҷ˵�
    r[0]=1;
    l[1]=0;
    idx=2;//����0,1��ռ��,idx��2��ʼ
}

void L(int x)//����˵����
{
    //�ȴ����µĽڵ�
    e[idx]=x;
    l[idx]=0;
    r[idx]=r[0];
    
    l[r[0]]=idx;
    r[0]=idx;
    idx++;
}

void R(int x)//���Ҷ˵����
{
    //�ȴ����µĽڵ�
    e[idx]=x;
    l[idx]=l[1];
    r[idx]=1;
    
    r[l[1]]=idx;
    l[1]=idx;
    idx++;
}

void insert(int k,int x)//��k���ұ߲���,����k����߲�����Ϊk����һ���ڵ���ұ�insert(l[k],x)
{
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void remove(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main()
{
    init();//��ʼ�� 
    
    int n;
    cin>>n;
    while(n--)
    {
        int k,x;
        string op;
        cin>>op;
        
        if(op=="L")//��˵����
        {
            cin>>x;
            L(x);
        }
        else if(op=="R")//�Ҷ˵����
        {
            cin>>x;
            R(x);
        }
        else if(op=="IL")//��k����߲���
        {
            cin>>k>>x;
            //��Ϊ�±�idx��2��ʼ������һ���������Ϊ2,�ڶ����������Ϊ3,����k++
            insert(l[k+1],x);
        }
        else if(op=="IR")//��k���ұ߲���
        {
            cin>>k>>x;
            //��Ϊ�±�idx��2��ʼ������һ���������Ϊ2,�ڶ����������Ϊ3,����k++
            insert(k+1,x);
        }
        else//ɾ��k��
        {
            cin>>k;
            //��Ϊ�±�idx��2��ʼ������һ���������Ϊ2,�ڶ����������Ϊ3,����k++
            remove(k+1);
        }
    }
    
    for(int i=r[0];i!=1;i=r[i])cout<<e[i]<<" ";//���
    cout<<endl;
    return 0;
}


