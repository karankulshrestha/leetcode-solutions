/*
    name: karankulx
    date: 01/03/2023
    Qlink: https://leetcode.com/problems/sort-an-array/description/
    Companies: GoldmanSachs, Microsoft, Cisco
*/

// Approach 1: Using Merge Sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        split(nums, res, 0, n);
        return nums;
    }
    void split(vector<int>& nums, vector<int>& res, int lo, int hi) {
        if(hi - lo < 2) return;
        int m = (hi + lo)/ 2;
        split(nums, res, lo, m);
        split(nums, res, m, hi);
        //merging
        int l = lo, r = m;
        for(int i = lo; i<hi; i++) {
            // if right side out of bound
            if(r == hi || (l < m && nums[l] <= nums[r])) {
                res[i] = nums[l];
                l++;
            } else {
                res[i] = nums[r];
                r++;
            }
        }
        copy(res.begin() + lo, begin(res) + hi, begin(nums) + lo);
    }
};

// Approach 2: Using Counting Sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        map<int, int> mp;
        for(int i : nums) {
            mp[i]++;
        }
        map<int, int> :: iterator it;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int val = mp[it->first];
            for(int j =0; j < val; j++) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};