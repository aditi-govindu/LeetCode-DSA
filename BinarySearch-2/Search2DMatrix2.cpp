/*
Q240. Description: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = size(matrix);
        int n = size(matrix[0]);
        
        // Start at last row column 0
        int i = m-1;
        int j = 0;
        
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] == target)
                return true;
            // Move right
            else if(matrix[i][j] < target)
                j++;
            // Move up
            else
                i--;
        }
        return false;
    }
};