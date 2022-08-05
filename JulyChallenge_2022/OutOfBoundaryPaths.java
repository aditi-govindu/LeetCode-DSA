/*
Q576. Description: There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
*/
class Solution 
{
    int M = 1000000007;
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        // memo = coordinates i,j, moves left to make
        int[][][] memo = new int [m][n][maxMove+1];
        for (int[][] l : memo) 
            for (int[] sl : l) Arrays.fill(sl, -1);
        return findPaths(m, n, maxMove, startRow, startColumn, memo);
    }
    
    public int findPaths(int m, int n, int N, int i, int j, int[][][] memo) 
    {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) return 0;
        if (memo[i][j][N] >= 0) return memo[i][j][N];
    memo[i][j][N] = (
        (findPaths(m, n, N - 1, i - 1, j, memo) + findPaths(m, n, N - 1, i + 1, j, memo)) % M +
        (findPaths(m, n, N - 1, i, j - 1, memo) + findPaths(m, n, N-1, i, j+1, memo))%M) % M;
    return memo[i][j][N];
  } 
}