/*
    name: Maximum Width of Binary Tree
    qlink: https://leetcode.com/problems/maximum-width-of-binary-tree/description/
    Companies: Flipkart, Microsoft, Amazon
*/

class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});
        ll maxWidth = 0;
        while(!que.empty()) {
            ll L = que.front().second;
            ll R = que.back().second;
            maxWidth = max(maxWidth, R - L + 1);
            ll n = que.size();
            while(n--) {
                TreeNode* curr = que.front().first;
                ll idx = que.front().second;
                que.pop();
                if(curr->left != NULL) {
                    que.push({curr->left, 2*idx + 1});
                }
                if(curr->right != NULL) {
                    que.push({curr->right, 2*idx + 2});
                }
            }

        }
        return maxWidth;
    }
};