/*
Q1572. Description: Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        // No diagonal for 1x1 matrix
        if(n == 1)
            return mat[0][0];

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;  j < n; j++)
            {
                // Consider element from secondary or primary diagonal only
                if(i + j == n - 1 || i == j)
                    sum += mat[i][j];
            }
        }
        return sum;
    }
};