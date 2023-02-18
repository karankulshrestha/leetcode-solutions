/*
    Name:karankulx
    Date:2/18/2023
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        struct TreeNode* temp;
        if(root == NULL) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};