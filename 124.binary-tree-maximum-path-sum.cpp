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
    struct result
    {
        int inc = INT_MIN, not_inc = INT_MIN;
    };
public:
    result maxSum(TreeNode* root)
    {
        result left, right;
        int cur = root->val, sum_t_l = INT_MIN, sum_t_r = INT_MIN, sum_all = INT_MIN;
        bool bool_t_l = false, bool_t_r = false, bool_all = false;
        int inc = INT_MIN, not_inc = INT_MIN;
        if(root->left)
        {
            left = maxSum(root->left);
        }
        if(root->right)
        {
            right = maxSum(root->right);
        }

        inc = cur;
        if(left.inc > right.inc)
        {
            inc+= left.inc;
        }
        else if(right.inc > left.inc)
        {
            inc += right.inc;
        }
        else if(right.inc != INT_MIN)
        {
            inc += right.inc;
        }
        if(cur > inc)
        {
            inc = cur;
        }
            
        if(left.inc != INT_MIN && right.inc != INT_MIN)
        {
            not_inc = cur + left.inc + right.inc;
        }
            
        if(left.not_inc > not_inc)
        {
            not_inc = left.not_inc;
        }
        if(right.not_inc > not_inc)
        {
            not_inc = right.not_inc;
        }
        if(left.inc > not_inc)
        {
            not_inc = left.inc;
        }
        if(right.inc > not_inc)
        {
            not_inc = right.inc;
        }
        
        return {inc, not_inc};
    }
    int findMax(TreeNode * root)
    {
        int left = INT_MIN, right = INT_MIN;
        if(root->left)
        {
            left = findMax(root->left);
        }
        if(root->right)
        {
            right = findMax(root->right);
        }
        if(root->val > left && root->val > right)
        {
            return root->val;
        }
        return left > right ? left : right;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        result ret;
        ret = maxSum(root);
        if(ret.inc == INT_MIN && ret.not_inc == INT_MIN)
        {
            return findMax(root);
        }
        return ret.inc > ret.not_inc ? ret.inc : ret.not_inc;
    }
};