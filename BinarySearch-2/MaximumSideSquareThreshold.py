'''
Q1292. Description: Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
'''

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        n,m = len(mat), len(mat[0])

        prefixSum = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        # Find prefix sum of every row
        for i in range(n):
            for j in range(m):
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] + mat[i][j] - prefixSum[i][j]

        max_side = 0

        # Update maximum square size
        for i in range(n):
            for j in range(m):
                # Is rectangle or square formed <= threshold
                if min(i, j) >= max_side:
                    curr = prefixSum[i + 1][j + 1]
                    top = prefixSum[i - max_side][j + 1]
                    left = prefixSum[i + 1][j - max_side]  
                    topLeft = prefixSum[i - max_side][j - max_side]
                    total = curr - top  - left + topLeft

                    # Update max_side if threshold reached
                    if total <= threshold:
                        max_side += 1
        
        return max_side