/*
    Name: karankulx
    Date: 2/19/2023
    company: amazon, uber
*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> items;
        items.push(root);
        bool lefttoright = true;
        while(!items.empty()) {
            int size = items.size();
            vector<int> row(size);
            for(int i = 0; i<size; i++) {
                TreeNode* node = items.front();
                items.pop();
                int index = (lefttoright) ? i : (size - 1 - i);
                row[index] = node->val;
                if(node->left) {
                    items.push(node->left);
                }
                if(node->right) {
                    items.push(node->right);
                } 
            }
            lefttoright = !lefttoright;
            ans.push_back(row);
        }
        return ans;
    }
};