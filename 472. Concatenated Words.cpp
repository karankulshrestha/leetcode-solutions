/*
    uname: karankulx
    date: 1/27/2023
    topic: dp, hashmap, recursion
    companies: meta, microsoft, airbnb
*/

class Solution {
public:
    bool isConcatenated(string word, unordered_set<string>& st) {
        int s = word.size();
        for(int i = 0; i < s; i++) {
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i + 1);
            if(st.find(prefix) != st.end() && isConcatenated(suffix, st)
                || (st.find(prefix) != st.end() && st.find(suffix) != st.end())) {
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words), end(words));
        vector<string> res;
        for(auto e: words) {
            if(isConcatenated(e, st)) {
                res.push_back(e);
            }
        }
        return res;
    }
};