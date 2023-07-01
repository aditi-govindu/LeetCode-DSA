/*
Q2328. Description: You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.
*/

class Solution 
{
    public int countPaths(int[][] grid) 
    {
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.length;
        int n = grid[0].length;
        int mod = 1_000_000_007;

        int[][] dp = new int[m][n];
        // Initialise dp to 1 -> Every cell has a path made by itself
        Arrays.stream(dp).forEach(row -> Arrays.fill(row, 1));

        // Sort all cells by value
        int[][] cellList = new int[m*n][2];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int index = i*n + j;
                cellList[index][0] = i;
                cellList[index][1] = j;
            }
        }
        Arrays.sort(cellList, (a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]);

        // Iterate over sorted cells by value
        for(int[] cell: cellList)
        {
            int i = cell[0], j = cell[1];
            for(int[] d: directions)
            {
                // If neighbour cell has larger value, increment current cell by neighbour
                int curri = i + d[0];
                int currj = j + d[1];

                if(curri >= 0 && curri < m && currj >= 0 && currj < n && 
                grid[curri][currj] > grid[i][j])
                {
                    dp[curri][currj] += dp[i][j];
                    dp[curri][currj] %= mod;
                }
            }
        }

        // Sum of paths over dp[i][j]
        int answer = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                answer += dp[i][j];
                answer %= mod;
            }
        }
        return answer;
    }
}