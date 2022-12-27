/* 
Q876. Description: Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
 */

class Solution {
    public ListNode middleNode(ListNode head) 
    {
        ListNode fast = head;
        ListNode slow = head;
        
        // When fast reaches end of list, slow is the middle
        while(fast != null && fast.next != null)
        {
            // Fast travels 2 elements at a time
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}