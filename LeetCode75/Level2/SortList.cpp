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
Q148. Description: Given the head of a linked list, return the list after sorting it in ascending order.
*/

class Solution 
{
public:
    ListNode* getMid(ListNode* head)
    {
        ListNode *midPrev = NULL;
        while(head && head -> next)
        {
            midPrev = (midPrev == NULL) ? head : midPrev -> next;
            head = head -> next -> next;
        }
        ListNode *mid = midPrev -> next;
        midPrev -> next = NULL;
        return mid;
    }
    
    ListNode* merge(ListNode *list1, ListNode* list2)
    {
        ListNode dummyHead(0);
        ListNode *nxt = &dummyHead;
        
        while(list1 && list2)
        {
            if(list1 -> val < list2 -> val)
            {
                nxt -> next = list1;
                list1 = list1 -> next;
            }
            else
            {
                nxt -> next = list2;
                list2 = list2 -> next;
            }
            nxt = nxt -> next;
        }
        if(list1)
            nxt -> next = list1;
        else
            nxt -> next = list2;
        return dummyHead.next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
};