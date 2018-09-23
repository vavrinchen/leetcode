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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = head;
        int length = 0;
        while(first != NULL)
        {
            length++;
            first = first->next; 
        }
        
        length = length - n;
        first = dummy;
        while(length > 0)
        {
            first = first->next;
            length--;
        }
        first->next = first->next->next;
        return dummy->next;
                
    }
};
