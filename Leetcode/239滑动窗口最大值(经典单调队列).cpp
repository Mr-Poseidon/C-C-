//������а�
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {       
        vector<int> ans;
        int win[100005];//�������
        int i=0,qh=0,qb=0;//i����ָ��,qh��ͷָ��,qb��βָ��
        while(i<k-1)
        {
            while(qb>qh && nums[i]>win[qb-1])qb--;//ȥСֵ
            win[qb++]=nums[i++];//���
        }
        while(i<nums.size())
        {
            while(qb>qh && nums[i]>win[qb-1])qb--;//ȥСֵ
            win[qb++]=nums[i++];//���

            ans.push_back(win[qh]);//ȡ��ֵ

            //����ǰ����Ԫ����ӣ����Զ�����Զ��Ϊ�գ�����ֱ�ӳ���
            if(nums[i-k]==win[qh])qh++;//����
        }
        return ans;
    }
}; 


//˫����а� 
class monotonicwindow
{
    private:
        deque<int> data;
    public:
        void push(int n)//��Ӻ��� 
        {
            while(!data.empty() && data.back()<n)//ȥ�����������б����ֵС��Ԫ�� 
                data.pop_back();
            data.push_back(n);//��� 
        }
        void pop(int n)//���Ӻ��� 
        {
        	//����������ӵ�Ԫ�رض����ڶ��е�����ߣ�����ÿ��ȥ�������е����ֵ 
        	//������ӵ�ֵ�����ǣ�������Ҫ�����жϣ�  data.front()==n 
            if(!data.empty() && data.front()==n)
                data.pop_front();
        }
        int max()
        {
            return data.front();//���ض������ֵ
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monotonicwindow win;        
        vector<int> ans;
        int i=0;//Ԫ��ָ�� 
        while(i<k-1)//��ʼ������ 
            win.push(nums[i++]);
        while(i<nums.size())//��ʼ���� 
        {
            win.push(nums[i++]);//��� 
            ans.push_back(win.max());//ȡ���ֵ 
            win.pop(nums[i-k]);//���� 
        }
        return ans;
    }
};
