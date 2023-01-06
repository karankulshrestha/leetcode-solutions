class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        if(costs[0] > coins) {
            return 0;
        };

        for(auto e : costs) {
            if(coins >= e) {
                coins -= e;
                cnt++;
            }
        }
        return cnt;
    }
};