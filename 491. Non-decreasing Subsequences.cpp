class Solution {
public:

    void backtrack(int ci, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums) {
        if(temp.size() >= 2) {
            ans.push_back(temp);
        }
        unordered_set<int> st;
        for(int i = ci; i < nums.size(); i++) {
            if((temp.empty() || nums[i] >= temp.back()) && (st.find(nums[i]) == st.end())) {
                temp.push_back(nums[i]);
                backtrack(i + 1, temp, ans, nums);
                temp.pop_back();
                st.insert(nums[i]);
            }
        }
    };

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(0, temp, ans, nums);

        return ans;
    };

};