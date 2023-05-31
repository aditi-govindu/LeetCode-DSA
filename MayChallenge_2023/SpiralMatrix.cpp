// Q54. Description: Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int>spiral;
        
        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;
        int direction = 1;
        
        while(top <= bottom && left <= right)
        {
            switch(direction)
            {
                // Left to right, copy elements as is
                case 1: for(int i = left; i <=right; i++)
                            spiral.push_back(matrix[top][i]);
                        // Increment 1 row as done and move to top -> bottom
                        direction = 2;
                        top++;
                        break;
                // Top to bottom, copy elements as is
                case 2:for(int i = top; i <= bottom; i++)
                            spiral.push_back(matrix[i][right]);
                        // Decrement 1 column and move to right -> left
                        direction = 3;
                        right--;
                        break;
                // Right to left, copy elements in reverse
                case 3:for(int i = right; i >= left; i--)
                            spiral.push_back(matrix[bottom][i]);
                        // Decrement 1 row and move to bottom -> top
                        direction = 4;
                        bottom--;
                        break;
                // Bottom to top, copy elements in reverse
                case 4:for(int i = bottom; i >= top; i--)
                            spiral.push_back(matrix[i][left]);
                        // Increment 1 row as done and move back to left -> right
                        direction = 1;
                        left++;
                        break;
            }
        }
        return spiral;
    }
};