//数组队列版
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {       
        vector<int> ans;
        int win[100005];//数组队列
        int i=0,qh=0,qb=0;//i数组指针,qh队头指针,qb队尾指针
        while(i<k-1)
        {
            while(qb>qh && nums[i]>win[qb-1])qb--;//去小值
            win[qb++]=nums[i++];//入队
        }
        while(i<nums.size())
        {
            while(qb>qh && nums[i]>win[qb-1])qb--;//去小值
            win[qb++]=nums[i++];//入队

            ans.push_back(win[qh]);//取最值

            //由于前面有元素入队，所以队列永远不为空，可以直接出队
            if(nums[i-k]==win[qh])qh++;//出队
        }
        return ans;
    }
}; 


//双向队列版 
class monotonicwindow
{
    private:
        deque<int> data;
    public:
        void push(int n)//入队函数 
        {
            while(!data.empty() && data.back()<n)//去除队列中所有比入队值小的元素 
                data.pop_back();
            data.push_back(n);//入队 
        }
        void pop(int n)//出队函数 
        {
        	//由于最先入队的元素必定会在队列的最左边，所以每次去除队列中的最大值 
        	//避免出队的值被覆盖，所以需要进行判断：  data.front()==n 
            if(!data.empty() && data.front()==n)
                data.pop_front();
        }
        int max()
        {
            return data.front();//返回队列最大值
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monotonicwindow win;        
        vector<int> ans;
        int i=0;//元素指针 
        while(i<k-1)//初始化窗口 
            win.push(nums[i++]);
        while(i<nums.size())//开始滑动 
        {
            win.push(nums[i++]);//入队 
            ans.push_back(win.max());//取最大值 
            win.pop(nums[i-k]);//出队 
        }
        return ans;
    }
};
