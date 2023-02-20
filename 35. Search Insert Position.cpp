/*
    name: karankulx
    date: 02/20/2023
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool cond = false;
        int ind = 0;
        int num = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                cond = true;
                ind = i;
            }
            if(nums[i] < target) {
                num = i + 1;
            }
        }
        if(cond) {
            return ind;
        } else {
            return num;
        }
    }
};