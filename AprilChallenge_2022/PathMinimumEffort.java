/*
Q1631. Description: You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution 
{
    public int minimumEffortPath(int[][] heights) 
    {
        final int row = 0, col = 1, effort = 2;
        final int rows = heights.length;
        final int columns = heights[0].length;
        // 4 directions to move - Up, Down, Left, Right
        final int[][] moves = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        boolean[][] visited = new boolean[rows][columns];
        int[][] best= new int[rows][columns];
        // Initialize best seen values to infinity, so far
        for(int[] b: best)
            Arrays.fill(b, Integer.MAX_VALUE);
        // Initialize priority queue for cells to visit
        Queue<int[]> queue = 
            new PriorityQueue<>((int[] v1, int[] v2)->v1[effort]-v2[effort]);
        best[0][0] = 0;
        queue.add(new int[]{0,0,0});
        while(!queue.isEmpty())
        {
            // Get vertex from priority queue
            int[] vertex = queue.remove();
            if(visited[vertex[row]][vertex[col]])
                continue;
            // Get effort of current cell
            int ef = vertex[effort];
            // If destination reached, return effort
            if(vertex[row] == rows-1 && vertex[col] == columns - 1)
                return ef;
            // Set vertex to visited
            visited[vertex[row]][vertex[col]] = true;
            // Check cost to move to adjacent cell
            for(int[] move: moves)
            {
                int r = vertex[row] + move[row];
                int c = vertex[col] + move[col];
                // If row is valid and not visited, move in 4 directions
                if (r >= 0 && r < rows && c >= 0 && c < columns && !visited[r][c])
                {
                    // Effort is maximum height difference
                    int veffort = Math.max(ef, Math.abs(
                        heights[r][c]-heights[vertex[row]][vertex[col]]));
                    if (veffort < best[r][c]) 
                    {
                        best[r][c] = veffort;
                        queue.add(new int[]{r, c, veffort});
                    }
                }
            }
        }
        return 0;
    }
}