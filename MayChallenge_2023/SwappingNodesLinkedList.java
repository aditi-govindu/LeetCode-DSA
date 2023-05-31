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

 /*
 Q1721. Description: You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
 */

class Solution 
{
    public int FindLength(ListNode root)
    {
        int len = 0;
        while(root != null)
        {
            len++;
            root = root.next;
        }
        return len;
    }
    
    public ListNode swapNodes(ListNode head, int k) {
        int len = 0;
        ListNode curr = head;
        len = FindLength(curr);
        int[] values = new int[len];
        int index = 0;

        // Store values in linked list in array
        while(head != null)
        {
            values[index++] = head.val;
            head = head.next;
        }

        // Swap nodes in array
        int temp = values[values.length - k];
        values[values.length - k] = values[k - 1];
        values[k - 1] = temp;
        
        // Create new list and append the nodes
        ListNode root = new ListNode(values[0]);
        ListNode duplicateHead = root;
        for(int i = 1; i < values.length; i++)
        {
            ListNode cpy = new ListNode();
            cpy.val = values[i];
            root.next = cpy;
            root = root.next;
        }
        return duplicateHead;
    }
}