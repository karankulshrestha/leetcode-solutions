/*
    companies: microsoft, amazon
    name: karankulx
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 1) {
            return mat[0][0];
        };
        int r = (n - 1)/2;
        int c = (m - 1)/2;
        int center = mat[r][c];
        int sum = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i==j) {
                    sum += mat[i][j];
                    sum += mat[i][m-j - 1];
                };
            };
        };
        if(n%2 != 0) {
            sum -= center;
        };
        return sum;
    }
};