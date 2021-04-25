class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());//排序
        for(int i=A.size()-1;i>=2;i--)
            if( A[i]<A[i-1]+A[i-2] )//最小两条边是否大于最长第三边 
                    return A[i]+A[i-1]+A[i-2];
    return 0;
    }
};



