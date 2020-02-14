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
    void add_path(int sum, int cur_sum, TreeNode * root,
                  vector<int> &cur_list, vector<vector<int >> &res)
    {
        if(cur_sum == sum && !root->left && !root->right)
        {
            vector<int> new_list (cur_list);
            //copy(cur_list, cur_list.size(), new_list);
            res.push_back(new_list);
            return;
        }
        if(root->left)
        {
            cur_list.push_back(root->left->val);
            add_path(sum, cur_sum + root->left->val, root->left, cur_list,
                    res);
            cur_list.pop_back();
            
        }
        if(root->right)
        {
            cur_list.push_back(root->right->val);
            add_path(sum, cur_sum + root->right->val, root->right, cur_list,
                    res);
            cur_list.pop_back();
            
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root )
        {
            return res;
        }
        vector<int> cur_list;
        cur_list.push_back(root->val);
        add_path(sum, root->val, root, cur_list, res);
        return res;
    }
};