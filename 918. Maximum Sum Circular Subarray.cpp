// Approach 1

class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int len = A.size();
        int ans1 = A[0]; 
        int ans2 = A[0];
        int curr = A[0];
       
        for(int i=1;i<len;i++)
        {
            curr = max(A[i],curr+A[i]);
            ans1 = max(ans1,curr);
        }
        curr = -1*A[0];
        ans2 = -1*A[0];
        int sum = accumulate(A.begin(),A.end(),0);
        for(int i=1;i<len;i++)
        {
            int val = (-1*A[i]);
            curr = max(val,curr+val);
            ans2 = max(ans2,curr);
        }
        if (sum+ans2==0)
            return ans1;
        return max(ans1,ans2+sum);
    }
};

//Approach 2

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }

    int minSum(vector<int>& arr) {
        int minSum = arr[0];
        int sum = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            sum = min(sum + arr[i], arr[i]);
            minSum = min(sum, minSum);
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int tsum = 0;
        for(auto e : nums) {
            tsum += e;
        }
        int maxs = maxSum(nums);
        int mins = minSum(nums);
        int csum = tsum - mins;
        if(maxs > 0) {
            return max(csum, maxs);
        }
        return maxs;
    }
};