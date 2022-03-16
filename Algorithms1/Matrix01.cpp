/*
Q542. Description: Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        // Return matrix if no rows
        if(rows == 0)
            return mat;
        int cols = mat[0].size();
        // Dynamic programming approach
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX - 100000));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(mat[i][j] == 0)
                    distance[i][j] = 0;
                else
                {
                    // Check minimum distance at top
                    if(i > 0)
                        distance[i][j] = min(distance[i][j], distance[i-1][j]+1);
                    // Check minimum distance to left
                    if(j > 0)
                        distance[i][j] = min(distance[i][j], distance[i][j-1]+1);
                }
            }
        }
        for(int i = rows - 1; i >= 0; i--)
        {
            for(int j = cols - 1; j >= 0; j--)
            {
                if(mat[i][j] == 0)
                    distance[i][j] = 0;
                else
                {
                    // Check minimum distance at bottom
                    if(i < rows - 1)
                        distance[i][j] = min(distance[i][j], distance[i+1][j]+1);
                    // Check minimum distance to right
                    if(j < cols - 1)
                        distance[i][j] = min(distance[i][j], distance[i][j+1]+1);
                }
            }
        }
        return distance;
    }
};