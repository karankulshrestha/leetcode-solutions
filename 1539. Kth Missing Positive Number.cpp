/*
    name: karankulx
    date: 06/03/2023
    companies: Google, Microsoft, Apple, Meta
    Qlink: https://leetcode.com/problems/kth-missing-positive-number/description/
    Approach: Binary Search
    Complexity less than O(n)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size();

        while(l < r) {
            int m = l + (r - l) / 2;
            if(arr[m] - m  > k) r = m;
            else l = m + 1;
        }
        return r + k;
    }
};