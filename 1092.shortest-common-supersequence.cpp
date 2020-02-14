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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> nodes;
        vector<int> res;
        if(root)
        {
            nodes.push(root);
        }
        TreeNode *cur;
        while(!nodes.empty())
        {
            cur = nodes.top();
            nodes.pop();
            res.insert(res.begin(), cur->val);
            if(cur->left)
            {
                nodes.push(cur->left);
            }
            if(cur->right)
            {
                nodes.push(cur->right);
            }
        }
        return res;
    }
};