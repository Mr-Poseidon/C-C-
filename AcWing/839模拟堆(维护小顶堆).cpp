#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;

//����ά��С����
//h[]Ϊ��
//ph[k]�����k����������ڶ��е��±�-pointer to heap(ָ���)
//hp[k]������±�Ϊk�����ǵڼ��β����-heap to pointer(�Ӷ���ָ����)
int h[N],hp[N],ph[N],sizes;

void heap_swap(int a,int b)
{
    swap(hp[a],hp[b]);//����Ĵ��򽻻�
    swap(ph[hp[a]],ph[hp[b]]);//�ڶ��е��±꽻��
    swap(h[a],h[b]);//ֵ����
}

void down(int k)//���¸���
{
    int t=k;//��tΪ��ǰ�����ڵ�����Сֵ���±� 
    if(k*2<=sizes && h[k*2]<h[t])t=k*2;//���������Ƚ�
    if(k*2+1<=sizes && h[k*2+1]<h[t])t=k*2+1;//���������Ƚ�
    if(t!=k)//������Ҫ������Сֵ
    {
        heap_swap(t,k);//����
        down(t);//�ݹ�
    }
}

void up(int k)//���ϸ���
{
    while(k/2 && h[k/2]>h[k])//���ڵ�����ӽڵ�
    {
        heap_swap(k/2,k);//����
        k/=2;//������
    }
}

void erase(int k)//ɾ������
{
    heap_swap(k,sizes);//β�ڵ㸲����Ҫɾ���Ľڵ�
    sizes--;//������--
    //ʵ�ʸ��²���ֻ��ִ��һ�֣�ֵ��ԭֵС�����ϸ��¡���ԭֵ�������¸���
    down(k),up(k);//����
}


int main()
{
    int n;
    scanf("%d",&n);
    
    char op[10];
    int k,x,m=0;//m�����m�β���
    
    for(int i=1;i<=n;i++)
    {
        scanf("%s",op);
        
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            sizes++;
            m++;
            
            h[sizes]=x;
            //up�������漰�����������ȼ�¼���ٸ���
            ph[m]=sizes;//��m�β�������ڶ��е��±�Ϊsizes
            hp[sizes]=m;//���±�Ϊsizes����Ϊ��m�β������
            up(sizes);//���������Ϊ���ڶѵף�ֻ�����ϸ���
        }
        else if(!strcmp(op,"PM"))printf("%d\n",h[1]);//������е���Сֵ�����Ѷ�
        else if(!strcmp(op,"DM"))erase(1);//ɾ���Ѷ�
        else if(!strcmp(op,"D"))//ɾ����k�β����ֵ
        {
            scanf("%d",&k);
            erase(ph[k]);//��k�β����ֵ�ڶ��е�С��Ϊph[k]
        }
        else if(!strcmp(op,"C"))//�޸ĵ�k�β����ֵΪx
        {
            scanf("%d%d",&k,&x);
            //�޸Ķ���Ԫ�ص�ֵ������Բ���Ĵ���Ͷ��±����Ӱ��
            k=ph[k];//�ҳ���k�β�������ڶ��е��±�
            h[k]=x;//�޸�
            //ʵ�ʸ��²���ֻ��ִ��һ�֣�ֵ��ԭֵС�����ϸ��¡���ԭֵ�������¸���
            down(k),up(k);//���¶�
        }
    }
    return 0;
}
