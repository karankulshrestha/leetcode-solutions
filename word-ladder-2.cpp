/*
    name: karankulx
    companies: Microsoft, Google, Amazon, Mbin, Oracle, SalesForce, etc
    qlink: https://leetcode.com/problems/word-ladder-ii/description/
*/

class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    string b;
private:
    void dfs(string word, vector<string>& seq) {
        if(b == word) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        };
        int steps = mp[word];
        int sz = word.size();
        for(int i = 0; i<sz; i++) {
            char original = word[i];
            for(char j = 'a'; j<='z'; j++) {
                word[i] = j;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                };
            };
            word[i] = original; 
        };
    };

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        b = beginWord;
        mp[beginWord] = 1;
        st.erase(beginWord);
        int sz = beginWord.size();
        while(!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0; i<sz; i++) {
                char original = word[i];
                for(char j = 'a'; j<='z'; j++) {
                    word[i] = j;
                    if(st.count(word)) {
                        q.push({word});
                        st.erase(word);
                        mp[word] = steps + 1;
                    };
                };
                word[i] = original; 
            };
        };
        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        };
        return ans;
    }
};