#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=9,M=1<<N;

int times[M],map[M];//times[state]维护state这个状态中1的个数，map[state]维护state这个状态对应的数字
int row[N],col[N],cell[3][3];//维护每行、每列、每个小九宫格中每个数字的填写状态
char str[100];

//用一个数来表示每行、每列、每个小九宫格中每个数字是否填写的状态
//用二进制表示每个位是否已经填写、0代表填写，1代表空，即未填写
// 987654321
// 111111111 若对应的二进制位上为1代表该位还没填写

void fillin(int x,int y,int t,bool is_set)//在（x,y）位置所对应的格子上填写数字t,is_set：true-填写，false-擦除
{
    if(is_set)str[x*N+y]='1'+t;//更新字符串中字符的状态
    else str[x*N+y]='.';
    
    int v=1<<t;//获取数字在二进制中代表的值
    if(is_set==false)v=-v;//取消就把值取反，方便后面进行剑法运算
    
    row[x]-=v;//更新行、列、大九宫格中的状态
    col[y]-=v;
    cell[x/3][y/3]-=v;
}

void init()
{
    for(int i=0;i<N;i++)row[i]=col[i]=(1<<N)-1;//将每行、每列的状态都初始化
    for(int i=0;i<3;i++)//初始化大九宫格中的状态
        for(int j=0;j<3;j++)
            cell[i][j]=(1<<N)-1;
}

int get(int x,int y)//获取（x,y）坐标中可以填写的所有数字代表的状态
{
    return row[x] & col[y] & cell[x/3][y/3];
}

int lowbit(int x)//返回最末尾的1的状态
{
    return x & -x;
}

bool dfs(int cnt)//深搜，cnt代表还需要填的数字的个数
{
    if(cnt==0)return true;//数字都填完了、返回true
    
    int minv=10;//w维护每个小九宫格中需要填的数字的个数、从最少的空位的格子开始填，优化搜索顺序
    int x,y;//维护填写的位置
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(str[i*N+j]=='.')//如果这个位置为空
            {
                int state=get(i,j);//获取该位置所在的小的九宫格的状态
                if(times[state]<minv)//该小格需要填的数字更少
                {
                    minv=times[state];//更新
                    x=i,y=j;//记录
                }
            }
    
    int state=get(x,y);//获取需要 填写的格子 所在的九宫格 所需要填写的所有数字 的 状态
    for(int i=state;i;i-=lowbit(i))//遍历所有需要填写的数字 的 状态
    {
        int t=map[lowbit(i)];//获取该状态所对应的数字
        fillin(x,y,t,true);/填写
        if(dfs(cnt-1))return true;
        fillin(x,y,t,false);//擦除
    }
    
    return false;//每个数字都无法填写、返回false
}

int main()
{
    //打表优化
    for(int i=0;i<N;i++)map[1<<i]=i;//初始化每个数字所对应的状态
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            times[i]+=i>>j&1;//初始化每个状态所对应的1的个数、即所需要填写的数字的个数
    
    while(cin>>str && str[0]!='e')//输入
    {
        init();//初始化
        
        int cnt=0;//cnt记录需要填写的数字的个数
        for(int i=0,k=0;i<N;i++)//遍历每个位置
            for(int j=0;j<N;j++,k++)
                if(str[k]!='.')//位置存在数字
                {
                    int t=str[k]-'1';//字符转化为数字
                    fillin(i,j,t,true);//填写
                }
                else cnt++;//需要填写的数字的个数+1
        
        dfs(cnt);//深搜
        
        puts(str);//输出结果
    }
    
    return 0;
}

