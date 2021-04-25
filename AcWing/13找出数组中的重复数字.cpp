/*����һ��
	�����������ڴ�ռ� 
*/ 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        
        int* map=new int[nums.size()];//�����¼ÿ�����ֳ��ֵĴ��� 
        for(int i=0;i<nums.size();i++)
            map[i]=0;
            
        for(int i=0;i<nums.size();i++)//����
        {
            if(nums.at(i)<nums.size())//�ڷ�Χ��
                map[nums.at(i)]++;
            else 
                return -1;
        }
        for(int i=0;i<nums.size();i++)//�ж��Ƿ����ظ�
            if(map[i]>1)
                return i;
        return -1;
    }
};


/*
��������
	�����鱾����Ԫ�أ�δ���������ڴ�
	ʱ�临�Ӷ�O(n) 
	swap()�� algorithm���У��������������������ĵ�ַ 
*/ 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        for(auto e:nums)//�ж������Ƿ��д���
            if(e<0 || e>=nums.size())
                return -1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=nums[nums[i]])//��������ȷ�ױ��ϵ�������ͬ
                swap(nums[i],nums[nums[i]]);//����һ�κ�ض�����һ�����ϵ���
            if(i!=nums[i])//�������һ����ȷ���������
                return nums[i];
        }
        return -1;
    }
};
