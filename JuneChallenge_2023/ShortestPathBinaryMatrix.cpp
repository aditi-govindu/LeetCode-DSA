/*
Q1091. Description: Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

class Solution 
{
    public int shortestPathBinaryMatrix(int[][] grid) 
    {
        if (grid[0][0]==1) return -1;
        int r=grid.length;
        int c=grid[0].length;

        Queue<int[]> q=new LinkedList<>();
        q.add(new int[]{0,0,1});
        grid[0][0]=1;

        // Travel in 8 directions: 4 NSEW and 4 diagonals
        int[][] dir={{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
        while(!q.isEmpty())
        {
            int sz=q.size();
            while(sz-- > 0)
            {
                int[] p=q.poll();
                if (p[0] == r-1 && p[1] == c-1 ) return p[2];
                
                for(int[] d : dir)
                {
                    int i=p[0]+d[0]; // update row
                    int j=p[1]+d[1]; // update column
                    
                    if (i<r && i>=0 && j<c && j>=0 && grid[i][j]==0) 
                    {
                        q.add(new int[]{i,j,p[2]+1});
                        grid[i][j]=1;
                    }
                }
            }
        }
        return -1;
    }
}