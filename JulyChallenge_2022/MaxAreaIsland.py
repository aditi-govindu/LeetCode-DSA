'''
Q695. Description: You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
'''

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # visited keeps track of all squares seen in grid
        visited = set()
        def area(r,c):
            # Check if square is within bounds of the grid, else return 0
            if not (0 <= r < len(grid) and 0 <= c < len(grid[0]) 
                    and (r,c) not in visited and grid[r][c]):
                return 0
            visited.add((r,c))
            # Sum of area of squares in all 4 directions - N,S,E,W
            return(1 + area(r+1,c) + area(r-1,c) + area(r,c+1) + area(r,c-1))
        
        return max(area(r,c) for r in range(len(grid)) for c in range(len(grid[0])))