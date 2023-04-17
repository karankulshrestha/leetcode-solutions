class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ver;
        for(auto i : candies) {
            int temp = i + extraCandies;
            bool ans = false;
            for(auto j : candies) {
                if(temp >= j) {
                    ans = true;
                } else {
                    ans = false;
                    break;
                }
            }
            if(ans) {
                ver.push_back(true);
            } else {
                ver.push_back(false);
            }
        }
        return ver;
    }
};