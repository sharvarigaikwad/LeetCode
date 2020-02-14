/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    void mark_rights(Node* parent, Node* current, bool isleft, Node* (&child), Node * (&child_parent), bool &isleft_child)
    {
        if(!child)
        {
            if(current->left)
            {
                child = current->left;
                child_parent = current;
                isleft_child = true;
            }
            else if(current->right)
            {
                child = current->right;
                child_parent = current;
                isleft_child = false;
            }
        }
        if(isleft && parent->right)
        {
            current->next = parent->right;
            mark_rights(parent, current->next, false, child, child_parent, isleft_child);
        }
        else
        {
            parent = parent->next;
            while(parent && !parent->left && !parent->right)
            {
                parent = parent->next;
            }
            if(!parent)
            {
                current->next = NULL;
                return;
            }
            else
            {
                if(parent->left)
                {
                    current->next = parent->left;
                    mark_rights(parent, current->next, true, child, child_parent, isleft_child);
                }
                else
                {
                    current->next = parent->right;
                    mark_rights(parent, current->next, false, child, child_parent, isleft_child);
                }
            }
        }
    }
    Node* connect(Node* root) {
        if(!root || (!root->left && !root->right))
        {
            return root;
        }
        root->next = NULL;
        Node * current, * parent;
        bool isleft = false, isleft_child = false;
        Node* child, *child_parent;
        if(root->left)
        {
            child = root->left;
            isleft_child = true;
        }
        else
        {
            child = root->right;
            isleft_child = false;
        }
        child_parent = root;
        do
        {
            current = child;
            parent = child_parent;
            isleft = isleft_child;
            child = NULL;
            child_parent = NULL;
            mark_rights(parent, current, isleft, child, child_parent, isleft_child);
        }while(child);
        return root;
    }
};