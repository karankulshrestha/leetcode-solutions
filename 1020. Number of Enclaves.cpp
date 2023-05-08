/*
    uname: karankulx
    companies: Google, Microsoft, Samsung, Amazon
    qlink: https://leetcode.com/problems/number-of-enclaves/description/
*/


class Solution {
public:
    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m) {
        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(grid[i][j] == 1 && vis[i][j] != 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    };
                };
            };
        };
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row >= 0 && row < n && col >= 0 && col < m && vis[row][col]  != 1 && grid[row][col] == 1) {
                    q.push({row, col});
                    vis[row][col] = 1;
                };
            };
        };

        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 1) {
                    cnt += 1;
                };
            };
        };

        return cnt;

    };

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return bfs(vis, grid, n, m);
    }
};