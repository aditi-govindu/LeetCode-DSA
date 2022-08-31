/*
Q48. Description: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        for(int i = 0; i < (n + 1)/2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                // Rotate cells in sets of 4
                int temp = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        
    }
};