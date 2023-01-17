class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c1 = 0;
        int flips = 0;
        for(auto e : s) {
            if (e == '1') {
                c1++;
            } else {
                flips = min(flips + 1, c1);
            }
        }
        return flips;
    }
};