/*
Q82. Description: Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* copy = new ListNode(0, head);
        ListNode* pred = copy;
        while(head != NULL)
        {
            // Identify sublist of repeated nodes
           if(head -> next != NULL && head -> val == head -> next -> val)
           {
               // Skip sublist of nodes by moving head ahead
               while(head -> next != NULL && head -> val == head -> next -> val)
                   head = head -> next;
               // Copy unique elements in ascending order
               pred -> next = head -> next;
           }
            else
            {
                // Move predecessor or nodes before the repetition
                pred = pred -> next;
            }  
            head = head -> next;
        }
        return copy -> next;
    }
};