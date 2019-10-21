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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> s[2];
        if(root)
        {
            s[0].push(root);
        }
        TreeNode * current;
        int cur = 0, next = 1;
        vector<vector<int>> solution;
        vector<int> this_level;
        bool change_queue = false;
        while(!s[cur].empty() )
        {
            current = s[cur].front();
            this_level.push_back(current->val);
            s[cur].pop();
            if(current->left)
            {
                s[next].push(current->left);
            }
            if(current->right)
            {
                s[next].push(current->right);
            }
            if(s[cur].empty())
            {
                cur = next + cur;
                next  = cur - next;
                cur = cur - next;
                if(!change_queue)
                {
                    change_queue = true;
                }
                else
                {
                    reverse(this_level.begin(), this_level.end());
                    change_queue = false;
                }
                solution.push_back(this_level);
                this_level.clear();
            }
        }
        return solution;
    }
};