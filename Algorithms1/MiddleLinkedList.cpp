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

/* Q876. Description: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        // Traverse list in reverse and append to an array
        while(A.back() -> next != NULL)
            A.push_back(A.back() -> next);
        // Return half of the array
        return A[A.size()/2];
    }
};