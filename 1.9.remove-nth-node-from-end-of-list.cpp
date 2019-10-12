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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ahead, *behind;
        ahead = head;
        behind = head;
        while ( n - 1 > 0 )
        {
            ahead = ahead->next;
            n--;
        }
        if(ahead->next == NULL)
        {
            behind = behind->next;
            //free(head);
            head = behind;
            return head;
        }
        ahead = ahead->next;
        while(ahead->next)
        {
            behind = behind->next;
            ahead = ahead->next;
        }
        ahead = behind->next;
        behind->next = behind->next->next;
        //free(ahead);
        return head;
    }
};