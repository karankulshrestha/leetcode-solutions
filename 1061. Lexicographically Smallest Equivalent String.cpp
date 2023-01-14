class Solution {
public:
    char checkDfs(unordered_map<char, vector<char>> &mp, char input, unordered_set<char>&visited) {
        if(visited.count(input) > 0) {
            return input;
        }
        visited.insert(input);
        char c = input;
        for(auto ch : mp[input]) {
            c = min(c, checkDfs(mp, ch, visited));
        }
        return c;
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> mp;
        for(int i = 0; i<s1.size(); i++) {
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        unordered_map<char, char> memo;
        string c;
        for(const auto s : baseStr) {
            if(memo.count(s) > 0) {
                c += memo[s];
                continue;
            }
            unordered_set<char> visited;
            const auto min_char = checkDfs(mp, s, visited);
            for(const auto ch : visited) {
                memo[ch] = min_char;
            }
            c += min_char;
        }
        return c;
    }
};