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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode *> bfs_q;
        if(root == NULL) 
		{
			return 0;
		}
        TreeNode * current;
        bfs_q.push(root);
        priority_queue<int> max_heap;
        while(!bfs_q.empty())
        {
            current = bfs_q.front();
            bfs_q.pop();
            if(current -> left)
                bfs_q.push(current->left);
            if(current -> right)
                bfs_q.push(current->right);
            max_heap.push(current->val);
            if(max_heap.size() > k)
                max_heap.pop();
        }
        return max_heap.top();
    }
};