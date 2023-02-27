/*
    name: karankulx
    date: 02/27/2023
    companies: Google, Uber, Ola, Zomato, Scaler, Lyft, Adobe.
    Question Link: https://leetcode.com/problems/construct-quad-tree/description/
*/

class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int n, int x, int y) {
        int val = grid[x][y];
        for(int i = x; i < x+n; i++) {
            for(int j = y; j < y+n; j++) {
                if(grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int n, int x, int y) {
        if(isAllSame(grid, n, x, y)) {
            return new Node(grid[x][y], true);
        } else {
            Node* root = new Node(1, false);
            root->topLeft = solve(grid, n/2, x, y);
            root->topRight = solve(grid, n/2, x, y + n/2);
            root->bottomLeft = solve(grid, n/2, x + n/2, y);
            root->bottomRight = solve(grid, n/2, x + n/2, y + n/2);
            return root;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, n, 0, 0);
    }
};