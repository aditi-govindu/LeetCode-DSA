/*
Q21. Description: You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode();
        // If 1 list is blank, return the other as it is
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;  
        if(list1 -> val < list2 -> val)
        {
            // If list 1 < list 2, copy list1 elements into final list
            merged = list1;
            merged -> next = mergeTwoLists(list1->next, list2);
        }
        else
        {
            // If list 2 < list 1, copy list2 elements into final list
            merged = list2;
            merged -> next = mergeTwoLists(list1, list2->next);
        }
        return merged;
    }
};