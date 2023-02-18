/*
    name: karankulx
    date: 2/17/2023
    companies: microsoft
*/


class Solution {
public:
    vector<int> vals;
    void fun(TreeNode* root) {
        if (root == NULL)
            return;
        fun(root->left);
        vals.push_back(root->val);
        fun(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        fun(root);
        int ans = INT_MAX;
        for(int i = 1; i<vals.size(); i++) {
            int sub = vals[i] - vals[i - 1];
            ans = min(sub, ans);
        }
        return ans;
    }
};