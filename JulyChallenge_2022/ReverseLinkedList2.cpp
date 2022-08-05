/*
 * Q92. Description: Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 */

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode *r = head;
        ListNode *p = NULL;
        ListNode *q = NULL;
        
        // Travel list till point where nodes are to be reversed
        while(left > 1)
        {
            p = r;
            r = r -> next;
            left--;
            right--;
        }
        
        // Store head of list that should not be changed
        ListNode *con = p;
        ListNode *tail = r;
        
        while(right > 0)
        {
            // Using 3 pointers to reverse the list
            q = r -> next;
            r -> next = p;
            p = r;
            r = q;
            right--;
        }
        
        // Attach unchanged nodes to list, as it is
        if(con != NULL)
            con -> next = p;
        else
            head = p;
        tail -> next = r;
        return head;
    }
};