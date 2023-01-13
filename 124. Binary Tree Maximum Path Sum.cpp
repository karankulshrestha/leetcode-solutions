class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);

        int m = l + r + root->val;
        int k = max(l, r) + root->val;
        int n = root->val;

        maxSum = max({maxSum, k, m, n});

        return max(k, n);
    };

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};