/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
 Q445. Description: You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        // Store elements of linked lists in descending order in stack
        while(l1)
        {
            int elem = l1 -> val;
            s1.push(elem);
            l1 = l1 -> next;
        }

        while(l2)
        {
            int elem = l2 -> val;
            s2.push(elem);
            l2 = l2 -> next;
        }

        int totalSum = 0, carry = 0;
        ListNode* ans = new ListNode();

        while(!s1.empty() || !s2.empty())
        {
            // Find sum of elements at top of both stacks in totalSum
            if(!s1.empty())
            {
                totalSum += s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                totalSum += s2.top();
                s2.pop();
            }

            // Store significant digit in answer node
            ans -> val = totalSum % 10;
            carry = totalSum / 10;
            // Create a new node to store carry of sum
            ListNode* newNode = new ListNode(carry);
            // Update node to move to next element in the list
            newNode -> next = ans;
            ans = newNode;
            totalSum = carry;
        }
        // If carry = 0, return next element to avoid head = 0 as answer
        return carry == 0 ? ans -> next : ans;
    }
};