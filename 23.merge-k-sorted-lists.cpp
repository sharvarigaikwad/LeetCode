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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [] (ListNode *a, ListNode *b) {return a->val > b->val;};
        priority_queue<ListNode *, vector<ListNode*>, decltype(comp)> min_heap(comp);
        for ( ListNode * head: lists)
        {
            if(head) 
			{
				min_heap.push(head);
			}
        }
        ListNode * head, *temp, * prev;
        if(min_heap.empty()) 
		{
			return NULL;
		}
        temp = min_heap.top();
        min_heap.pop();
        head = temp;
        prev = head;
        if(temp->next) 
		{
			min_heap.push(temp->next);
		}
        while(!min_heap.empty())
        {
            temp = min_heap.top();
            min_heap.pop();
            prev->next = temp;
            prev = temp;
            if(temp->next) 
			{
				min_heap.push(temp->next);
			}
        }
        return head;
    }
};