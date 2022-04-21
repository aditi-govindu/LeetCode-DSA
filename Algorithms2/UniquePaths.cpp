/*
Q62. Description: There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize array to 0
        int result[m][n];
        memset(result, 0, sizeof(result));
        result[0][0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // If down movement is allowed, add move to result
                if(i-1 >= 0)
                    result[i][j] += result[i-1][j];
                // If right move is allowed, add move to result
                if(j-1 >= 0)
                    result[i][j] += result[i][j-1];
            }
        }
        // Corner cell will store count of all moves
        return result[m-1][n-1];
    }
};