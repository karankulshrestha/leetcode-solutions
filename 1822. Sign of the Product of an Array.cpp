class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto e : nums) {
            if(!e) return 0;
            if(e < 0) {
                ans *= -1;
            }
        };
        return ans;
    };
};