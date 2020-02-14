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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *leftRet = NULL, *rightRet = NULL;
        if(root == p || root == q)
        {
            return root;
        }
        if(!root)
        {
            return NULL;
        }
        if(root->left)
        {
            leftRet = lowestCommonAncestor(root->left, p, q);
        }
        if(root->right)
        {
            rightRet = lowestCommonAncestor(root->right, p, q);
        }
        if(leftRet && rightRet)
        {
            return root;
        }
        else if(!leftRet && rightRet)
        {
            return rightRet;
        }
        else if(leftRet && !rightRet)
        {
            return leftRet;
        }
        return NULL;
    }
};