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
Q2. Description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode head1 = l1;
        ListNode head2 = l2;
        ListNode curr = dummy;
        int carry = 0;
        while(head1 != null || head2 != null)
        {
            int x,y;
            if(head1 != null)
                x = head1.val;
            else
                x = 0;
            if(head2 != null)
                y = head2.val;
            else
                y = 0;
            int sum = carry + x + y;
            carry = sum/10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if(head1 != null)
                head1 = head1.next;
            if(head2 != null)
                head2 = head2.next;
        }
        if(carry > 0)
            curr.next = new ListNode(carry);
        return dummy.next;
    }
}