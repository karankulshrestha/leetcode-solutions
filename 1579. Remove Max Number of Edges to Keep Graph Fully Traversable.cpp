/*
    name: karankulx
    qname: 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
    Companies: Google, Microsoft, deloitte
    Qlink: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
*/

class Solution {
public:
    int find(int node, vector<int> &parent) {
        if(parent[node] == -1) {
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }

    bool Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        if(pa == pb) {
            return false;
        } else {
            if(rank[pa] > rank[pb]) {
                parent[pb] = pa;
                rank[pa]++;
            } else if(rank[pb] > rank[pa]) {
                parent[pa] = pb;
                rank[pb]++;
            } else {
                parent[pb] = pa;
                rank[pa]++;
            }
            return true;
        }
        return true;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b) {
            return a[0] > b[0];
        });
        int cnt = 0;
        vector<int> parAlice(n+1, -1);
        vector<int> parBob(n+1, -1);
        vector<int> rankAlice(n+1, -1);
        vector<int> rankBob(n+1, -1);

        for(int i = 0; i<edges.size(); i++) {
            if(edges[i][0] == 3) {
                bool t1 = Union(edges[i][1], edges[i][2], parAlice, rankAlice);
                bool t2 = Union(edges[i][1], edges[i][2], parBob, rankBob);
                if(t1 == false && t2 == false) {
                    cnt++;
                }
            } else if(edges[i][0] == 2) {
                bool t3 = Union(edges[i][1], edges[i][2], parBob, rankBob);
                if(t3 == false) {
                    cnt++;
                }
            } else {
                bool t4 = Union(edges[i][1], edges[i][2], parAlice, rankAlice);
                if(t4 == false) {
                    cnt++;
                }
            }
        }
        int itr1=0, itr2=0;
        for(int i = 1; i<n+1; i++) {
            if(parAlice[i] == -1) itr1++;
            if(parBob[i] == -1) itr2++;
        };
        if(itr1 == 1 && itr2 == 1) return cnt;
        return -1;
    }
};