
// Leetcode : 2359. Find Closest Node to Given Two Nodes
// Level: Medium

//company tags: microsoft, uber, amazon, microsoft engage

/*
    uname: Karankulx
    Date: 1/25/2023
*/

// Concepts: BFS -->> finding shortest path 

class Solution {
public:
    int n;

    void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited) {
        visited[node] = true;
        int u = edges[node];
        if(u != -1 && !visited[u]) {
            visited[u] = true;
            dist[u] = dist[node] + 1;
            dfs(edges, u, dist, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        vector<bool> v1(n, false), v2(n, false);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, node1, dist1, v1);
        dfs(edges, node2, dist2, v2);

        int mindn = -1;
        int mindtn = INT_MAX;

        for(int i = 0; i<n; i++) {
            int maxd = max(dist1[i], dist2[i]);
            if(mindtn > maxd) {
                mindtn = maxd;
                mindn = i;
            }
        }
        return mindn;
    }
};