/*
    name: "1697. Checking Existence of Edge Length Limited Paths"
    link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/
    Companies: Google, Meta
*/

class UnionFind {
    public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n) {
        for(int i = 0; i<n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    void Union(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if(pi == pj) {
            return;
        }
        if(rank[pi] > rank[pj]) {
            parent[pj] = pi;
        } else if(rank[pi] < rank[pj]) {
            parent[pi] = pj;
        } else {
            parent[pi] = pj;
            rank[pj]++;
        }
    }
    int find(int i){
        if(parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
};

class Solution {
    static bool comp(vector<int>& a, vector<int>& b) { 
        return a[2] < b[2];
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i<queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        UnionFind uf(n);
        int j = 0;
        for(int i = 0; i<queries.size(); i++) {
            for(; j < edgeList.size() && edgeList[j][2] < queries[i][2]; j++) {
                uf.Union(edgeList[j][0], edgeList[j][1]);
            }
            ans[queries[i][3]] = uf.find(queries[i][0]) == uf.find(queries[i][1]) ? 1 : 0;
        }
        return ans;
    }
};