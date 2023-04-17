/*
Q74. Description: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int i = 0;
        int j = matrix[0].size() - 1;
        
        while(i < rows && j >= 0)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};