/*
    name: karankulx
    date: 02/22/2023
    companies: meta, amazon, uber
*/

class Solution {
public:
    bool check(vector<int>& weight, int days, int capacity) {
        int requiredDays = 1;
        int itemWeight = 0;
        for(auto i : weight) {
            if(itemWeight + i > capacity) {
                requiredDays++;
                itemWeight = 0;
            }
            itemWeight += i;
        }
        if(requiredDays > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for(auto i : weights) {
            left = max(left, i);
            right += i;
        }
        int mid;
        int ans = right;
        while(left <= right) {
            mid = (right + left)/2;
            if(check(weights, days, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};