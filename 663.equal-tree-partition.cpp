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
    int getLeftRightVals(TreeNode * node, map<TreeNode*, pair<int, int>> & sums)
    {
        int left = 0, right = 0;
        
        if(node->left)
        {
            left = getLeftRightVals(node->left, sums);
        }
        if(node->right)
        {
            right = getLeftRightVals(node->right, sums);
        }
        sums[node] = make_pair(left, right);
        return left + right + node->val;
    }
    bool foundNode(TreeNode * node, map<TreeNode *, pair<int, int>> sum, int parent)
    {
        pair<int, int> children_vals = sum[node];
        if(node->left && parent + children_vals.second + node->val == 
          children_vals.first)
        {
            return true;
        }   
        if(node->right && parent + children_vals.first + node->val ==
          children_vals.second)
        {
            return true;
        }   
        if(node->left && foundNode(node->left, sum, parent+node->val+children_vals.second) == true)
        {
            return true;
        }
        if(node->right)
        {
            return foundNode(node->right, sum, parent+node->val+children_vals.first);
        }
        return false;
        
    }
    bool checkEqualTree(TreeNode* root) {
        if(!root)
        {
            return false;
        }
        map<TreeNode *, pair<int, int>> sums;
        int ret = getLeftRightVals(root, sums);
        if(ret % 2)
            return false;
        return foundNode(root, sums, 0);
    }
};