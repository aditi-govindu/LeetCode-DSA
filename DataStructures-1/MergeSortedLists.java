/*
Q21. Description: You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

class Solution 
{
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