/*
Q200. Description: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution 
{
public:
    void Explore(vector<vector<char>>& grid, int x, int y)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        // Explore up, down, left, right
        Explore(grid, x-1, y);
        Explore(grid, x+1, y);
        Explore(grid, x, y+1);
        Explore(grid, x, y-1);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    Explore(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};