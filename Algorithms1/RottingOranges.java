/*
Q994. Description: You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
    public int orangesRotting(int[][] grid) {
        // Return 0 for no oranges
        if(grid.length == 0 || grid[0].length == 0 || grid == null)
            return 0;
        int rows = grid.length;
        int columns = grid[0].length;
        
        Queue<int[]>q = new LinkedList<>();
        int fresh = 0;
        
        for(int i =0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                // Add index of rotten orange(2) to queue
                if(grid[i][j] == 2)
                    q.offer(new int[]{i,j});
                // Increment count of fresh orange(1)
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        int minutes = 0;
        // Check if cell is empty or orange being impacted is negative
        int[][] dir = new int[][]{{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.isEmpty() && fresh > 0)
        {
            int len = q.size();
            for(int i = 0;  i < len; i++)
            {
                // DeQueue first rotten orange
                int[] orange = q.poll();
                for(int[] d : dir)
                {
                    // If orange can be rotten, set it to 2
                    int x = orange[0] + d[0];
                    int y = orange[1] + d[1];
                    if(x < 0 || y < 0 || x >= rows || y >= columns || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;
                    grid[x][y] = 2;
                    // Add orange to rotten queue
                    q.offer(new int[]{x,y});
                    // Decrement fressh count
                    fresh--;
                }
            }
            minutes++;
        }
    if(fresh == 0)
        return minutes;
    return -1;
    }
}