/*
    name: karankulx
    date: 02/21/2023
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto e : nums) {
            mp[e]++;
        }
        for(auto e : mp) {
            if(e.second == 1) {
                ans = e.first;
            }
        }
        return ans;
    }
};