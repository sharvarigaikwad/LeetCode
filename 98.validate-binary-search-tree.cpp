/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* root, long min_val, long max_val)
    {
        if(root->val <= min_val || root->val >= max_val)
        {
            return false;
        }
        return (root->left ? validate(root->left, min_val, root->val) : 1) &&
            (root->right ? validate(root->right, root->val, max_val) : 1);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        return (root->left ? validate(root->left, LONG_MIN, root->val) : 1) && 
            (root->right ? validate(root->right, root->val, LONG_MAX) : 1);
    }
};