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
        set<TreeNode*> visited;
        vector<int> res;
        if(root)
        {
            nodes.push(root);
        }
        TreeNode *cur;
        while(!nodes.empty())
        {
            cur = nodes.top();
            if(visited.count(cur))
            {
                res.push_back(cur->val);
                nodes.pop();
            }
            else
            {
                visited.insert(cur);
                
                if(cur->right)
                {
                    nodes.push(cur->right);
                }
                if(cur->left)
                {
                    nodes.push(cur->left);
                }
            }
        }
        return res;
    }
};