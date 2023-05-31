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
 Q2130. Description: In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
 */

class Solution {
public:
    int pairSum(ListNode* head) 
    {
        // Get values of all nodes in the linked list
        vector<int> values;
        while(head)
        {
            values.push_back(head -> val);
            head = head -> next;
        }
        int max = 0;
        int n = values.size();

        for(int i = 0; i < n; i++)
        {
            // Add node i and n-i-1. If it current largest, set value
            int temp = values[i] + values[n - i - 1];
            max = (temp > max) ? temp : max;
        }
        return max;
    }
};