
/*
    name: karankulx
    date: 05/03/2023
    Qlink: https://leetcode.com/problems/jump-game-iv/
    Companies: Google, Facebook, Microsoft
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int step = 0;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i<n; i++) {
            graph[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        list<int> queue;
        queue.push_back(0);
        visited[0] = true;
        while(!queue.empty()) {
            for(int i = queue.size(); i>0; i--) {
                int node = queue.front();
                queue.pop_front();
                if(node == n - 1) return step;
                vector<int>& next = graph[arr[node]];
                next.push_back(node - 1); next.push_back(node + 1);
                for(auto nxt : next) {
                    if(nxt >= 0 && !visited[nxt] && nxt < n) {
                        visited[nxt] = true;
                        queue.push_back(nxt);
                    }
                }
                graph[arr[node]].clear();
            }
            step++;
        }
        return 0;
    }
};