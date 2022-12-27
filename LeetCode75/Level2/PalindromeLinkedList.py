# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
Q234. Description: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
'''

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # Convert linked list to string and compare with reverse
        data = ''
        while(head):
            data += (str)(head.val)
            head = head.next
        return data == data[::-1]