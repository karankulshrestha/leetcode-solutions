/*
    name: karankulx
    date: 02/28/2023
    Qlink: https://leetcode.com/problems/find-duplicate-subtrees/description/
    companies: google, microsoft, amazon
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string mark = ",";

    string findDup(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mp) {
        string ans = "";
        if(root == NULL)
            return mark + ans;
        string serial = to_string(root->val)  + 
                        findDup(root->right, res, mp) + findDup(root->left, res, mp);
        
        if(mp[serial] == 1) {
            res.push_back(root);
        }
        mp[serial]++;
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mp;
        findDup(root, res, mp);
        return res;
    }
};