/*
    name: karankulx
    date: 02/24/2023
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> PQ;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] % 2 != 0) {
                nums[i] *= 2;
            }
        }
        for(int j : nums) {
            PQ.insert(j);
        }
        int diff = *PQ.rbegin() - *PQ.begin();
        while(*PQ.rbegin() % 2 == 0) {
            int top = *PQ.rbegin();
            int temp = top / 2;
            PQ.erase(top);
            PQ.insert(temp);
            diff = min(diff, *PQ.rbegin() - *PQ.begin());
        }
        return diff;
    }
};