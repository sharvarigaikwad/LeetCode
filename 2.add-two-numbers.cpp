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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        if(l1 && l2)
        {
            sum = l1->val+l2->val;
            if (sum >= 10)
            {
                carry = sum / 10; sum %= 10;
            }
            l1=l1->next; l2=l2->next;
        }
        ListNode * res = new ListNode(sum), * prev;
        prev = res;
        while (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            if (sum >= 10 )
            {
                carry = sum / 10; sum %= 10;
            }
            else {carry = 0;}
            ListNode * temp = new ListNode(sum);
            prev-> next = temp;
            prev=temp;
            l1 = l1->next; l2=l2->next;
        }
        while(l1)
        {
            sum = l1->val + carry;
            if(sum >= 10) 
            {
                carry = sum/10; sum %= 10;
            }
            else {carry=0;}
            ListNode * temp = new ListNode(sum);
            prev->next=temp;
            prev=temp;
            l1 = l1->next;
        }
        while(l2)
        {
            sum = l2->val + carry;
            if(sum >= 10) 
            {
                carry = sum/10; sum %= 10;
            }
            else {carry=0;}
            ListNode * temp = new ListNode(sum);
            prev->next=temp;
            prev=temp;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode * temp = new ListNode(carry);
            prev->next = temp;
        }
        return res;
    }
};