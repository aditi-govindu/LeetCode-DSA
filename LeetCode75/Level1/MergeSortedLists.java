/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// Q21. Merge 2 sorted linked lists
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) 
    {
        ListNode newhead = new ListNode();
        // If any list is NULL, return the other
        if(list1 == null)
            return list2;
        if(list2 == null)
            return list1;
        if(list1.val < list2.val)
        {
            // Copy list 1 whose value is less than list 2
            newhead = list1;
            newhead.next = mergeTwoLists(list1.next, list2);
        }
        else
        {
            newhead = list2;
            // Copy next element by recursively checking for smaller element or NULL list
            newhead.next = mergeTwoLists(list1, list2.next);
        }
        return newhead;
    }
}