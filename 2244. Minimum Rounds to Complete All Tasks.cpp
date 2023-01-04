class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int rnd = 0;
        map<int, int> mp;
        for(auto e : tasks) {
            mp[e]++;
        }
        map<int, int>::iterator it = mp.begin();
        while (it != mp.end())
        {
            int num = it->second;
            if(num == 1) {
                rnd = -1;
                break;
            }
            if(num % 3 <= 2) {
                int t = num % 3;
                if(t == 0) {
                    rnd += num/3;
                } else if(t <= 2) {
                    rnd += num/3 + 1;
                };
            }
            it++;
        }
        return rnd;
    }
};