/*
Q74. Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int i = 0;
        int j = matrix[0].length - 1;
        while(i < matrix.length && j >= 0)
        {
            // Start from last cell in row 1
            if(matrix[i][j] == target)
                return true;
            // If element in matrix is smaller, go to next row
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
}