/*
    name: karankulx
    date: 02/03/2023
    Qlink: https://leetcode.com/problems/string-compression/description/
    Companies: Amazon, Google, Meta, Microsoft
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('~');
        vector<char> ans;
        int cnt = 1;
        for(int i = 1; i<chars.size(); i++) {
            if(chars[i - 1] == chars[i]) cnt++;
            else {
                if(cnt == 1) ans.push_back(chars[i - 1]), cnt = 1;
                else {
                    ans.push_back(chars[i - 1]);
                    string temp = to_string(cnt);
                    for(auto e : temp) {
                        ans.push_back(e);
                    }
                    cnt = 1;
                }
            }
        }
        chars = ans;
        return ans.size();
    }
};