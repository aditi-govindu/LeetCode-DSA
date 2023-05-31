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
 Q24. Description: Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 */
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* temp = head -> next;
        
        head -> next = swapPairs(head -> next -> next);

        temp -> next = head;
        return temp;
    }
};