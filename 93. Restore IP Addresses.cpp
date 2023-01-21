class Solution {
public:
    vector<string> ans;
    void backtrack(string res, string curr, int ind, string s) {
        if(s.size() == ind) {
            if(curr.empty() && count(res.begin(), res.end(), '.') == 3) {
                ans.push_back(res);
            }
            return;
        }
        if(!curr.empty() and stoi(curr)==0){
            return;
        }
        curr.push_back(s[ind]);
        if(stoi(curr) > 255) {
            return;
        }
        backtrack(res, curr, ind + 1, s);
        if(!res.empty()) {
            backtrack(res + "." + curr, "", ind + 1, s);
        } else {
            backtrack(curr, "", ind + 1, s);
        }
    };

    vector<string> restoreIpAddresses(string s) {
        backtrack("", "", 0, s);
        return ans;
    }
};