/*
Q200. Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

class Solution {
    public void DFS(char[][]grid, int x, int y)
    {
        // Check if x and y are within the matrix
        if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        // Explore all 4 directions - Up, down, left, right
        DFS(grid, x+1, y);
        DFS(grid, x-1, y);
        DFS(grid, x, y-1);
        DFS(grid, x, y+1);
    }
    
    public int numIslands(char[][] grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.length; i++)
        {
            for(int j = 0; j < grid[0].length; j++)
            {
                if(grid[i][j] == '1')
                {
                    // Increment count by 1, everytime function returns to main
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
}