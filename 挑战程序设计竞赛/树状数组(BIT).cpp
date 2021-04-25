//树状数组的模板

 
#include<vector>
using namespace std;

vector<int> bit;
vector<int> ori;// 记录原始数组，从而能够在update的时候计算出位置i处的值的变化量
                // bit是该数组的反应

int low_bit(int x){
    return x & (-x);
}

// 给定原数据有边界下标值，求其前缀和 
int prefixSum(int i)
{
	//注：树状数组下标由 1 开始,0弃置 
    i+=1;
    int sum=0;
    while(i>0){
        sum+= bit[i];
        i-=low_bit(i);
    }
    return sum;
}
    
void init(vector<int>& nums)//初始化 
{
    ori.push_back(0);
    ori.insert(ori.end(), nums.begin(), nums.end());

    bit.push_back(0);
    bit.insert(bit.end(), nums.begin(), nums.end());

    // 初始化bit,复杂度O(n),依次单点更新复杂度O(nlogn),优化了logn 
    // 即根据给定i，更新所有能包含到i的右边界
    for (int i = 1; i < bit.size(); i++)
	{
        int j = i + low_bit(i);
        if (j < bit.size())
			bit[j] += bit[i];
    }
}

// 注意此处是将i下标的值更新为val，而不是在原基础上增加val
// 但是原理还是一样的，先求出其变化值
void update(int i, int val) {
    i += 1;
    int dec = val - ori[i];  // 注意bit中记录的是区间和，ori记录的才是bit对应的原始数组
    ori[i] = val;

    while(i < bit.size()){
        bit[i] += dec;
        i += low_bit(i);
    }
}

// 求原数组闭区间[i,j]的和
int sumRange(int i, int j){
    return prefixSum(j) - prefixSum(i-1);
}

int main()
{
	return 0;
}
