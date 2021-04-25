/*方法一：
	有申请额外的内存空间 
*/ 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        
        int* map=new int[nums.size()];//数组记录每个数字出现的次数 
        for(int i=0;i<nums.size();i++)
            map[i]=0;
            
        for(int i=0;i<nums.size();i++)//遍历
        {
            if(nums.at(i)<nums.size())//在范围内
                map[nums.at(i)]++;
            else 
                return -1;
        }
        for(int i=0;i<nums.size();i++)//判断是否有重复
            if(map[i]>1)
                return i;
        return -1;
    }
};


/*
方法二：
	在数组本身交换元素，未额外申请内存
	时间复杂度O(n) 
	swap()在 algorithm库中，交换的是两个迭代器的地址 
*/ 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        for(auto e:nums)//判断数据是否有错误
            if(e<0 || e>=nums.size())
                return -1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=nums[nums[i]])//该数与正确底标上的数不相同
                swap(nums[i],nums[nums[i]]);//交换一次后必定产生一个符合的数
            if(i!=nums[i])//避免最后一次正确交换后输出
                return nums[i];
        }
        return -1;
    }
};
