class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());
        for(auto i : a) {
            if(b.count(i) == 0) {
                ans[0].push_back(i);
            };
        };
        for(auto j : b) {
            if(a.count(j) == 0) {
                ans[1].push_back(j);
            };
        };
        return ans;
    }
};