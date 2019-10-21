/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *parent = head, * temp;
        if(!head || !head->next) 
        {
            return head;
        }
        int prev_val = head->next->val - 1;
        while(parent && parent->next && parent->val == parent->next->val)
        {
            prev_val = parent->val;
            while(parent && parent->val == prev_val)
            {
                parent = parent->next;
            }
        }
        if(!parent || !parent->next)
        {
            return parent;
        }
        head = parent;
        temp = parent;
        parent = parent;
        while(parent->next)
        {
            if(parent->next->val == prev_val)
            {
                parent->next = parent->next->next;
                if(parent->val == prev_val)
                {
                    temp->next = parent->next;
                    parent = temp;
                }
            }
            else
            {
                prev_val = parent->next->val;
                temp = parent;
                parent = parent->next;
            }
        }
        return head;
    }
};