/* Q86. Description: Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *before_head = new ListNode(0);
        ListNode *before = before_head;
        ListNode *after_head = new ListNode(0);
        ListNode *after = after_head;
        
        while(head)
        {
            // If head < val, copy in before list
            if( head -> val < x)
            {
                before -> next = head;
                before = before -> next;
            }
            else
            {
                // Copy node into after list
                after -> next = head;
                after = after -> next;
            }
            head = head -> next;
        }
        after -> next = NULL;
        
        // Merge both lists
        before -> next = after_head -> next;
        return before_head -> next;
    }
};