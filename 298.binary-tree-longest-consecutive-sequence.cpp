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
    int longestConsecutive(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        pair<int, bool> ret = longestConsecutiveHelper(root);
        return ret.first;
    }
    pair<int, bool> longestConsecutiveHelper(TreeNode * root)
    {
        int l = 0, r = 0;
        bool lbool = false, rbool = false;
        pair<int, bool> res;
        int max = 1;
        int maxinc = true;
        if(root->left)
        {
            res = longestConsecutiveHelper(root->left);
            l = res.first;
            if (root->left->val == root->val + 1 )
            {
                if(res.second != true)
                {
                    if(l > 2)
                    {
                        max = l;
                        maxinc = false;
                    }
                    else
                    {
                        max = 2;
                        maxinc = true;
                    }
                }
                else
                {
                    max = l+1;
                    maxinc = true;
                }
            }
            else 
            {
                if(l > 1)
                {
                    max = l;
                    maxinc = false;
                }
            }
        }
        if(root->right)
        {
            res = longestConsecutiveHelper(root->right);
            r = res.first;
            if (root->right->val == root->val + 1)
            {
                if(res.second != true)
                {
                    if(r > 2 && max < r)
                    {
                        max = r;
                        maxinc = false;
                    }
                    else if(max < 2)
                    {
                        max = 2;
                        maxinc = true;
                    }
                    
                }
                else
                {
                    if(max <= r+1)
                    {
                        max = r+1;
                        maxinc = true;
                    }
                }
            }
            else
            {
                if(r > max)
                {
                    max = r;
                    maxinc = false;
                }
                else if (max <= 1)
                {
                    max = 1;
                    maxinc = true;
                }
            }
        }
        return make_pair(max, maxinc);
    }
};