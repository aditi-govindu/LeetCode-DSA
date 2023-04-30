/*
Q1254. Description: Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

class Solution 
{
public:
    vector<pair<int, int>> dir{{0,1},{1,0},{-1, 0}, {0, -1}};
    int n, m;

    bool DFS(vector<vector<int>>&grid, int i, int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;
        
        if(grid[i][j] == 1 || grid[i][j] == 2)
            return true;
        
        // If seen, set cell to 2
        grid[i][j] = 2;

        bool flag = true;
        // Iterate over all cells the perform AND operation to get 1 for water around island
        for(auto it: dir)
            flag &= DFS(grid, i + it.first, j+it.second);
        return flag;
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Skip if cell is an island or already seen
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    continue;

                // If all water around island, increment count of islands
                if(DFS(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};