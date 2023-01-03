class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> strcols;
        int dcol = 0;
        for(int i = 0; i < strs[0].size(); i++) {
            string temp = "";
            for(auto e : strs) {
                temp += e[i];
            }
            strcols.push_back(temp);
        }

        for(auto e : strcols) {
            string t = e;
            sort(t.begin(), t.end());
            if(t != e) {
                dcol += 1;
            }
        }
        return dcol;
    }
};