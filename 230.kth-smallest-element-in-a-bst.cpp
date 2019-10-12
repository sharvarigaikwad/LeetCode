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

    TreeNode *inOrderTraverse(TreeNode * node, int &k)
    {
        TreeNode * temp;
        if(node->left)
        {
            temp = inOrderTraverse(node->left, k);
            if(temp) 
			{
				return temp;
			}
        }
        if(!k || k == 1) 
			return node;
        k--;
        if(node -> right)
        {
            temp = inOrderTraverse(node->right, k);
            if(temp) 
			{
				return temp;
			}
        }
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inOrderTraverse(root, k)->val;
    }
};