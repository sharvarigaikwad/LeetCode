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
    void reverseList(ListNode *start, ListNode *end)
    {
        if(start == end)
        {
            return;
        }
        if(start->next == end)
        {
            end->next = start;
            start->next = NULL;
            return;
            //return make_pair<ListNode *, ListNode *> (start, end);
        }
        ListNode * p, * q, * temp;
        p = start;
        q = start->next;
        end->next = NULL;
        while(q)
        {
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        //return make_pair<ListNode*, ListNode *> (end, start);
        //returns pair- pointer to first and pointer to last
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * start = head, * end = head, * prev, * follow;
        int i;
        if(!start || !start->next)
        {
            return start;
        }
        for(i = 1; i < k && end; i ++)
        {
            end = end->next;
        }
        if(!end)
        {
            return head;
        }
        follow = end->next;
        reverseList(start, end);
        head = end;
        prev = start;
        prev->next = follow;
        start = follow;
        end = follow;
        while(end && end->next)
        {
            for(i = 1; i < k && end; i++)
            {
                end = end->next;
            }
            if(!end)
            {
                return head;
            }
            follow = end->next;
            reverseList(start, end);
            prev->next = end;
            prev = start;
            start = follow;
            end = follow;
            prev-> next = follow;
        }
        return head;
    }
};