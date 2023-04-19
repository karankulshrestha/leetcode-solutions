
/*
    uname: karankulx
    Name: 1372. Longest ZigZag Path in a Binary Tree
    Qlink: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
    Companies: Microsoft, Amazon
*/


// Approach 1: Using Recursion 1

class Solution {
public:
    int maxPath = 0;
    void solve(TreeNode* root, int steps, bool goLeft) {
        if(root == NULL) {
            return;
        }
        maxPath = max(maxPath, steps);
        if(goLeft == true) {
            solve(root->left, steps + 1, false);
            solve(root->right, 1, true);
        } else {
            solve(root->right, steps + 1, true);
            solve(root->left, 1, false);
        }
    }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, true);
        solve(root, 0, false);
        return maxPath;
    }
};

// Approach 2: Using Recursion 2

class Solution {
public:
    int maxPath = 0;
    void solve(TreeNode* root, int l, int r) {
        if(root == NULL) {
            return;
        }
        maxPath = max({maxPath, l, r});
        solve(root->left, r + 1, 0);
        solve(root->right, 0, l + 1);
    }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        return maxPath;
    }
};