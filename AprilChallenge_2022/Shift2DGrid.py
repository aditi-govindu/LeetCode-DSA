'''
Q1260. Description: Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
'''

class Solution:                
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        order = []
        # Convert 2D matrix to 1D list
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                order.append(grid[i][j])
        # Add elements to queue
        queue = deque(order)
        # Pop from queue and add to left for every iteration
        while k != 0:
            queue.appendleft(queue.pop())
            k -= 1
        result, check = [], []
        length = len(grid[0])
        while queue:
            check.append(queue.popleft())
            if len(check) == length:
                result.append(check)
                check = []
        return result    