/*
    name: karankulx
    companies: Microsoft, Google, Salesforce, Amazon
    link: https://leetcode.com/problems/spiral-matrix/description/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        int dir = 1;
        vector<int> ans;
        while(left<=right && top<= bottom) {
            if(dir == 1) {
                for(int i = left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                };
                top++;
                dir = 2;
            } else if(dir == 2) 
            {
                for(int i = top; i<=bottom; i++) {
                    ans.push_back(matrix[i][right]);
                };
                right--;
                dir = 3;
            } else if (dir == 3) 
            {
                for(int i = right; i>= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                };
                bottom--;
                dir = 4;
            } else if(dir == 4) 
            {
                for(int i = bottom; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                };
                dir = 1;
                left++;
            };
        };
        return ans; 
    }
};