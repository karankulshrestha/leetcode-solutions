class Solution {
public:
    map<int, bool> vis;
    map<int, list<int> > adj;

    void dfs(int node) {
        vis[node] = true;
        list<int>::iterator i;
        for (i = adj[node].begin(); i != adj[node].end(); ++i) {
            if(!vis[*i]) {
                dfs(*i);
            }
        }
    }

    bool checkSim(string s1, string s2) {
        int cnt = 0;
        int n = s1.size();
        for(int i = 0; i<n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
                if(cnt > 2)
                    return false;
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(checkSim(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};