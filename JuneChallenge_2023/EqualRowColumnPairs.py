'''
Q2352. Description: Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
'''

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid)

        # Compare all row-column pairs
        for row in range(n):
            for col in range(n):
                match = True

                for i in range(n):
                    # If row and column not equal, break loop and go to next set
                    if grid[row][i] != grid[i][col]:
                        match = False
                        break
                count += int(match)

        return count