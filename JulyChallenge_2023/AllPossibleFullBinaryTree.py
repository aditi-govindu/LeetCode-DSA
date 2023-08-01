# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

'''
Q894. Description: Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.
'''

class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        # No FBT possible with even nodes
        if n%2 == 0:
            return []
        if n == 1:
            # Empty tree with 1 null node
            return [TreeNode()]
        
        res = []
        # Iterate over 2 nodes at a time and make FBT
        for i in range(1, n, 2):
            left = self.allPossibleFBT(i)
            right = self.allPossibleFBT(n - i - 1)

            for l in left:
                # For each element in left and right lists, set root -> left, root -> right
                for r in right:
                    root = TreeNode(0, l, r)
                    res.append(root)
        
        return res
            