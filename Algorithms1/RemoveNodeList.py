'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

Q19. Description: Given the head of a linked list, remove the nth node from the end of the list and return its head.
'''

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        fast = dummy
        slow = head
        # While list is not empty
        while n > 0 and slow:
            slow = slow.next
            n=n-1
        while slow:
            fast = fast.next
            slow = slow.next
            
        fast.next = fast.next.next
        return dummy.next