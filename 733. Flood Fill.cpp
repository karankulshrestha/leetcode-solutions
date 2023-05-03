/*
    uname: karankulx
    name: flood fill
    companies: Amazon, Google and Microsoft
    qlink: https://leetcode.com/problems/flood-fill/description/
*/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int inicolor, int fillcolor, vector<vector<int>>& ans) {
        ans[sr][sc] = fillcolor;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0; i<4; i++) {
            int r = sr + drow[i];
            int c = sc + dcol[i];
            if( r >= 0 && r < image.size() && c >= 0 && c < image[0].size() && ans[r][c] != fillcolor && ans[r][c] == inicolor) {
                dfs(image, r, c, inicolor, fillcolor, ans);
            };
        };
    };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(image, sr, sc, inicolor, color, ans);
        return ans;
    };
};