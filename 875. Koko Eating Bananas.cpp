/*
    name: karankulx
    date: 08/03/2023
    companies: Meta, Amazon, Oracle, Microsoft
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for(auto x : piles) {
                cnt += (x + mid - 1) / mid;
            }
            if(cnt > h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};