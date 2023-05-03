
/*
    name: karankulx
    qname: cycle detection
    companies: Google, Amazon, Microsoft, Delloite
*/

// cycle detection using dfs

class Solution {
  public:
    bool detect(int src, vector<int> adj[], vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjnode : adj[node]) {
                if(!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, node});
                } else if(parent != adjnode) {
                    //detect cycle
                    return true;
                };
            };
        };
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
            };
        };
        return false;  
    }
};

// cycle detection using dfs

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, int parent, vector<int> adj[], vector<int>& vis) {
        vis[src] = 1;
        for(auto adjnode: adj[src]) {
            if(!vis[adjnode]) {
                vis[adjnode] = 1;
                if(detect(adjnode, src, adj, vis)) {
                    return true;
                };
            } else if(adjnode != parent) {
                return true; // detect cycle
            };
        };
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, -1, adj, vis)) return true;
            };
        };
        return false;
    };
};